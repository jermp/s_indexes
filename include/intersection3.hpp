#pragma once

#include "constants.hpp"
#include "decode3.hpp"
#include "uncompress3.hpp"

#define chunk_pair(l, r) (3 * (l) + (r))
#define block_pair(l, r) (2 * (l) + (r))

namespace sliced {

size_t ss_intersect_block3(uint8_t const* l, uint8_t const* r, int card_l,
                           int card_r, uint32_t base, uint32_t* out) {
    assert(uint32_t(card_l) > 0 and
           uint32_t(card_l) <= constants::block_sparseness_threshold - 2);
    assert(uint32_t(card_r) > 0 and
           uint32_t(card_r) <= constants::block_sparseness_threshold - 2);
    uint8_t const* end_l = l + card_l;
    uint8_t const* end_r = r + card_r;
    size_t size = 0;
    while (true) {
        while (*l < *r) {
            if (++l == end_l) {
                return size;
            }
        }
        while (*l > *r) {
            if (++r == end_r) {
                return size;
            }
        }
        if (*l == *r) {
            out[size++] = *l + base;
            if (++l == end_l or ++r == end_r) {
                return size;
            }
        }
    }
    return size;
}

size_t ds_intersect_block3(uint8_t const* l, uint8_t const* r, int card,
                           uint32_t base, uint32_t* out) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(l);
    uint32_t k = 0;
    for (int i = 0; i != card; ++i) {
        uint32_t key = r[i];
        out[k] = key + base;
        k += bitmap_contains(bitmap, key);
    }
    return k;
}

size_t ss_intersect_chunk3(uint8_t const* l, uint8_t const* r, int blocks_l,
                           int blocks_r, uint32_t base, uint32_t* out) {
    assert(blocks_l >= 1 and blocks_l <= 256);
    assert(blocks_r >= 1 and blocks_r <= 256);
    uint8_t const* data_l = l + blocks_l * 2;
    uint8_t const* data_r = r + blocks_r * 2;
    uint32_t* tmp = out;

    int pl = 0;
    int pr = 0;
    while (true) {
        while (*l < *r) {
            if (++pl == blocks_l) {
                return size_t(tmp - out);
            }
            data_l += *(l + 1);
            l += 2;
        }
        while (*l > *r) {
            if (++pr == blocks_r) {
                return size_t(tmp - out);
            }
            data_r += *(r + 1);
            r += 2;
        }
        if (*l == *r) {
            uint8_t id = *l;
            ++l;
            ++r;
            int card_l = *l;
            int card_r = *r;
            int type_l = TYPE_BY_CARDINALITY(card_l);
            int type_r = TYPE_BY_CARDINALITY(card_r);

            uint32_t b = base + id * 256;
            uint32_t n = 0;
            switch (block_pair(type_l, type_r)) {
                case block_pair(type::sparse, type::sparse):
                    n = ss_intersect_block3(data_l, data_r, card_l, card_r, b,
                                            tmp);
                    break;
                case block_pair(type::sparse, type::dense):
                    n = ds_intersect_block3(data_r, data_l, card_l, b, tmp);
                    break;
                case block_pair(type::dense, type::sparse):
                    n = ds_intersect_block3(data_l, data_r, card_r, b, tmp);
                    break;
                case block_pair(type::dense, type::dense):
                    n = dd_intersect_block(data_l, data_r, b, tmp);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            tmp += n;

            if (++pl == blocks_l or ++pr == blocks_r) {
                return size_t(tmp - out);
            }

            data_l += card_l;
            data_r += card_r;
            ++l;
            ++r;
        }
    }

    return size_t(tmp - out);
}

size_t ds_intersect_chunk3(uint8_t const* l, uint8_t const* r, int blocks_r,
                           uint32_t base, uint32_t* out) {
    static uint64_t x[1024];
    std::fill(x, x + 1024, 0);
    uncompress_sparse_chunk3(r, blocks_r, x);
    return dd_intersect_chunk(l, reinterpret_cast<uint8_t const*>(x), base,
                              out);
}

size_t fs_intersect_chunk3(uint8_t const* l, uint8_t const* r, int blocks_r,
                           uint32_t base, uint32_t* out) {
    (void)l;
    return decode_sparse_chunk3(r, blocks_r, base, out);
}

size_t pairwise_intersection3(s_sequence const& l, s_sequence const& r,
                              uint32_t* out) {
    auto it_l = l.begin();
    auto it_r = r.begin();
    size_t size = 0;
    while (it_l.has_next() and it_r.has_next()) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            uint32_t base = id_l << 16;
            int blocks_l = 0;
            int blocks_r = 0;
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):

                    blocks_l = it_l.blocks();
                    blocks_r = it_r.blocks();
                    if (blocks_l < blocks_r) {
                        n = ss_intersect_chunk3(it_l.data, it_r.data, blocks_l,
                                                blocks_r, base, out);
                    } else {
                        n = ss_intersect_chunk3(it_r.data, it_l.data, blocks_r,
                                                blocks_l, base, out);
                    }

                    // n = ss_intersect_chunk3(it_l.data, it_r.data,
                    // it_l.blocks(),
                    //                         it_r.blocks(), base, out);
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = ds_intersect_chunk3(it_r.data, it_l.data, it_l.blocks(),
                                            base, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = fs_intersect_chunk3(it_r.data, it_l.data, it_l.blocks(),
                                            base, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = ds_intersect_chunk3(it_l.data, it_r.data, it_r.blocks(),
                                            base, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = dd_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = fd_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = fs_intersect_chunk3(it_l.data, it_r.data, it_r.blocks(),
                                            base, out);
                    break;
                case chunk_pair(type::full, type::dense):
                    n = fd_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::full, type::full):
                    n = ff_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            out += n;
            size += n;
            it_l.next();
            it_r.next();

        } else if (id_l < id_r) {
            it_l.advance(id_r);
        } else {
            it_r.advance(id_l);
        }
    }
    return size;
}

}  // namespace sliced