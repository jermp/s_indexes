#pragma once

#include "constants.hpp"
#include "uncompress.hpp"
#include "decode.hpp"

namespace sliced {

size_t ss_union_block(uint8_t const* l, uint8_t const* r, int card_l,
                      int card_r, uint32_t base, uint32_t* out) {
    assert(card_l > 0 and
           card_l <= int(constants::block_sparseness_threshold - 2));
    assert(card_r > 0 and
           card_r <= int(constants::block_sparseness_threshold - 2));
    size_t size = 0;
    uint8_t const* end_l = l + card_l;
    uint8_t const* end_r = r + card_r;

    while (true) {
        if (*l < *r) {
            out[size++] = *l + base;
            ++l;
            if (l == end_l) {
                break;
            }
        } else if (*r < *l) {
            out[size++] = *r + base;
            ++r;
            if (r == end_r) {
                break;
            }
        } else {
            out[size++] = *l + base;
            ++l;
            ++r;
            if (l == end_l or r == end_r) {
                break;
            }
        }
    }

    while (l != end_l) {
        out[size++] = *l + base;
        ++l;
    }

    while (r != end_r) {
        out[size++] = *r + base;
        ++r;
    }

    return size;
}

size_t union_bitmaps(uint8_t const* l, uint8_t const* r,
                     size_t size_in_64bit_words, uint32_t base, uint32_t* out) {
    uint64_t const* bitmap_l = reinterpret_cast<uint64_t const*>(l);
    uint64_t const* bitmap_r = reinterpret_cast<uint64_t const*>(r);
    size_t pos = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap_l[i] | bitmap_r[i];
        while (w != 0) {
            uint64_t t = w & (~w + 1);
            int r = __builtin_ctzll(w);
            out[pos++] = r + base;
            w ^= t;
        }
        base += 64;
    }
    return pos;
}

size_t ds_union_block(uint8_t const* l, uint8_t const* r, int cardinality,
                      uint32_t base, uint32_t* out) {
    static uint64_t x[4];
    memcpy(x, reinterpret_cast<uint64_t const*>(l), constants::block_size / 8);
    uncompress_sparse_block(r, cardinality, x);
    return union_bitmaps(l, reinterpret_cast<uint8_t const*>(x),
                         constants::block_size_in_64bit_words, base, out);
}

size_t ss_union_chunk(uint8_t const* l, uint8_t const* r, int blocks_l,
                      int blocks_r, uint32_t base, uint32_t* out) {
    assert(blocks_l >= 1 and blocks_l <= 256);
    assert(blocks_r >= 1 and blocks_r <= 256);

    uint8_t const* data_l = l + blocks_l * 2;
    uint8_t const* data_r = r + blocks_r * 2;
    uint8_t const* end_l = data_l;
    uint8_t const* end_r = data_r;
    uint32_t* tmp = out;

    while (true) {
        while (*l < *r) {
            uint8_t id = *l;
            int bytes = *(l + 1);
            tmp += decode_block(data_l, bytes, base + id * 256, tmp);
            if (l + 2 == end_l) {
                return size_t(tmp - out);
            }
            data_l += bytes;
            l += 2;
        }
        while (*l > *r) {
            uint8_t id = *r;
            int bytes = *(r + 1);
            tmp += decode_block(data_r, bytes, base + id * 256, tmp);
            if (r + 2 == end_r) {
                return size_t(tmp - out);
            }
            data_r += bytes;
            r += 2;
        }
        if (*l == *r) {
            uint8_t id = *l;
            ++l;
            ++r;
            int bytes_l = *l;
            int bytes_r = *r;
            int type_l = TYPE_BY_BYTES(bytes_l);
            int type_r = TYPE_BY_BYTES(bytes_r);

            uint32_t b = base + id * 256;
            uint32_t n = 0;

            switch (block_pair(type_l, type_r)) {
                case block_pair(type::sparse, type::sparse):
                    n = ss_union_block(data_l, data_r, bytes_l, bytes_r, b,
                                       tmp);
                    break;
                case block_pair(type::sparse, type::dense):
                    n = ds_union_block(data_r, data_l, bytes_l, b, tmp);
                    break;
                case block_pair(type::dense, type::sparse):
                    n = ds_union_block(data_l, data_r, bytes_r, b, tmp);
                    break;
                case block_pair(type::dense, type::dense):
                    n = union_bitmaps(data_l, data_r,
                                      constants::block_size_in_64bit_words, b,
                                      tmp);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            tmp += n;

            if (l + 1 == end_l or r + 1 == end_r) {
                return size_t(tmp - out);
            }

            data_l += bytes_l;
            data_r += bytes_r;
            ++l;
            ++r;
        }
    }

    while (l != end_l) {
        uint8_t id = *l;
        int bytes = *(l + 1);
        tmp += decode_block(data_l, bytes, base + id * 256, tmp);
        data_l += bytes;
        l += 2;
    }

    while (r != end_r) {
        uint8_t id = *r;
        int bytes = *(r + 1);
        tmp += decode_block(data_r, bytes, base + id * 256, tmp);
        data_r += bytes;
        r += 2;
    }

    return size_t(tmp - out);
}

size_t ds_union_chunk(uint8_t const* l, uint8_t const* r, int blocks_r,
                      uint32_t base, uint32_t* out) {
    static std::vector<uint64_t> x(1024);
    std::fill(x.begin(), x.end(), 0);
    uncompress_sparse_chunk(r, blocks_r, x.data());
    return union_bitmaps(l, reinterpret_cast<uint8_t const*>(x.data()),
                         constants::chunk_size_in_64bit_words, base, out);
}

size_t pairwise_union(s_sequence const& l, s_sequence const& r, uint32_t* out) {
    auto it_l = l.begin();
    auto it_r = r.begin();
    uint32_t* in = out;

    while (true) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            uint32_t base = id_l << 16;
            int blocks_l = 0;
            int blocks_r = 0;

            uint16_t type_l = it_l.type();
            uint16_t type_r = it_r.type();

            switch (chunk_pair(type_l, type_r)) {
                case chunk_pair(type::sparse, type::sparse):
                    blocks_l = it_l.blocks();
                    blocks_r = it_r.blocks();
                    if (blocks_l < blocks_r) {
                        n = ss_union_chunk(it_l.data, it_r.data, blocks_l,
                                           blocks_r, base, out);
                    } else {
                        n = ss_union_chunk(it_r.data, it_l.data, blocks_r,
                                           blocks_l, base, out);
                    }
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = ds_union_chunk(it_r.data, it_l.data, it_l.blocks(),
                                       base, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = ds_union_chunk(it_l.data, it_r.data, it_r.blocks(),
                                       base, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = union_bitmaps(it_l.data, it_r.data,
                                      constants::chunk_size_in_64bit_words,
                                      base, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::full, type::dense):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::full, type::full):
                    n = decode_full_chunk(base, out);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            out += n;

            it_l.next();
            if (!it_l.has_next()) {
                break;
            }

            it_r.next();
            if (!it_r.has_next()) {
                break;
            }

        } else if (id_l < id_r) {
            out += decode_chunk(it_l, out);
            it_l.next();
            if (!it_l.has_next()) {
                break;
            }
        } else {
            out += decode_chunk(it_r, out);
            it_r.next();
            if (!it_r.has_next()) {
                break;
            }
        }
    }

    while (it_l.has_next()) {
        out += decode_chunk(it_l, out);
        it_l.next();
    }

    while (it_r.has_next()) {
        out += decode_chunk(it_r, out);
        it_r.next();
    }

    return size_t(out - in);
}

}  // namespace sliced