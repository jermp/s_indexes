#pragma once

#include "configuration.hpp"
#include "decode.hpp"
#include "uncompress.hpp"

#define chunk_pair(l, r) (3 * (l) + (r))
#define block_pair(l, r) (4 * (l) + (r))

namespace sliced {

size_t ss_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    uint32_t card_l = *l++;
    uint32_t card_r = *r++;

    uint8_t const* end_l = l + card_l;
    uint8_t const* end_r = r + card_r;
    size_t size = 0;

    do {  // avoid testing condition for most-frequent case
        if (*l == *r) {
            out[size++] = *l;
            ++l;
            ++r;
        } else if (*l < *r) {
            ++l;
        } else {
            ++r;
        }
    } while (l < end_l and r < end_r);

    return size;
}

size_t intersect_bitmap(uint8_t const* l, uint8_t const* r,
                        size_t size_in_64bit_words, uint32_t* out) {
    uint64_t const* bitmap_l = reinterpret_cast<uint64_t const*>(l);
    uint64_t const* bitmap_r = reinterpret_cast<uint64_t const*>(r);
    __m256i base_vec = _mm256_set1_epi32(-1);
    __m256i inc_vec = _mm256_set1_epi32(64);
    __m256i add8 = _mm256_set1_epi32(8);

    size_t decoded = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap_l[i] & bitmap_r[i];
        if (w == 0) {
            base_vec = _mm256_add_epi32(base_vec, inc_vec);
        } else {
            for (int k = 0; k < 4; ++k) {  // process 2 bytes of data at a time
                uint8_t byte1 = (uint8_t)w;
                uint8_t byte2 = (uint8_t)(w >> 8);
                w >>= 16;
                __m256i vec1 = _mm256_load_si256(
                    (const __m256i*)tables::dictionary[byte1]);
                __m256i vec2 = _mm256_load_si256(
                    (const __m256i*)tables::dictionary[byte2]);
                uint8_t advance1 = tables::size[byte1];
                uint8_t advance2 = tables::size[byte2];
                vec1 = _mm256_add_epi32(base_vec, vec1);
                base_vec = _mm256_add_epi32(base_vec, add8);
                vec2 = _mm256_add_epi32(base_vec, vec2);
                base_vec = _mm256_add_epi32(base_vec, add8);
                _mm256_storeu_si256((__m256i*)(out + decoded), vec1);
                decoded += advance1;
                _mm256_storeu_si256((__m256i*)(out + decoded), vec2);
                decoded += advance2;
            }
        }
    }
    return decoded;
}

size_t dd_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    return intersect_bitmap(l, r, constants::block_size_in_64bit_words, out);
}

size_t ds_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    static uint64_t x[4];
    std::fill(x, x + 4, 0);
    uncompress_sparse_block(r, x);
    return dd_intersect_block(l, reinterpret_cast<uint8_t const*>(x), out);
}

size_t fs_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_sparse_block(r, out);
}

size_t fd_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_dense_block(r, out);
}

size_t ff_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)r;
    return decode_full_block(l, out);
}

size_t ss_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    uint8_t const* data_l = l + 64;
    uint8_t const* data_r = r + 64;
    uint32_t* tmp = out;
    uint32_t base = 0;
    uint32_t size = 0;

    for (uint32_t i = 0; i != 64; ++i) {
        uint8_t header_byte_l = l[i];
        uint8_t header_byte_r = r[i];

        if (header_byte_l == 0 and header_byte_r == 0) {
            base += 256 * 4;
        } else {
            for (uint32_t i = 0; i != 4; ++i) {
                uint8_t header_l = header_byte_l & 3;
                uint8_t header_r = header_byte_r & 3;
                uint32_t n = 0;
                uint32_t d = 0;

                switch (block_pair(header_l, header_r)) {
                    case block_pair(type::empty, type::empty):
                        break;
                    case block_pair(type::empty, type::sparse):
                        d = *data_r;
                        data_r += d + 1;
                        break;
                    case block_pair(type::empty, type::dense):
                        data_r += 32;
                        break;
                    case block_pair(type::empty, type::full):
                        break;

                    case block_pair(type::sparse, type::empty):
                        d = *data_l;
                        data_l += d + 1;
                        break;
                    case block_pair(type::sparse, type::sparse):
                        n = ss_intersect_block(data_l, data_r, tmp);
                        d = *data_l;
                        data_l += d + 1;
                        d = *data_r;
                        data_r += d + 1;
                        break;
                    case block_pair(type::sparse, type::dense):
                        n = ds_intersect_block(data_r, data_l, tmp);
                        data_r += 32;
                        d = *data_l;
                        data_l += d + 1;
                        break;
                    case block_pair(type::sparse, type::full):
                        n = fs_intersect_block(data_r, data_l, tmp);
                        data_l += n + 1;
                        break;

                    case block_pair(type::dense, type::empty):
                        data_l += 32;
                        break;
                    case block_pair(type::dense, type::sparse):
                        n = ds_intersect_block(data_l, data_r, tmp);
                        data_l += 32;
                        d = *data_r;
                        data_r += d + 1;
                        break;
                    case block_pair(type::dense, type::dense):
                        n = dd_intersect_block(data_l, data_r, tmp);
                        data_l += 32;
                        data_r += 32;
                        break;
                    case block_pair(type::dense, type::full):
                        n = fd_intersect_block(data_r, data_l, tmp);
                        data_l += 32;
                        break;

                    case block_pair(type::full, type::empty):
                        break;
                    case block_pair(type::full, type::sparse):
                        n = fs_intersect_block(data_l, data_r, tmp);
                        data_r += n + 1;
                        break;
                    case block_pair(type::full, type::dense):
                        n = fd_intersect_block(data_l, data_r, tmp);
                        data_r += 32;
                        break;
                    case block_pair(type::full, type::full):
                        n = ff_intersect_block(data_r, data_l, tmp);
                        break;

                    default:
                        assert(false);
                        __builtin_unreachable();
                }

                for (size_t i = 0; i != n; ++i) {
                    tmp[i] += base;
                }

                tmp += n;
                base += 256;
                size += n;
                header_byte_l >>= 2;
                header_byte_r >>= 2;
            }
        }
    }

    return size;
}

size_t dd_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    return intersect_bitmap(l, r, constants::chunk_size_in_64bit_words, out);
}

size_t ds_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    static uint64_t x[1024];
    std::fill(x, x + 1024, 0);
    uncompress_sparse_chunk(r, x);
    return dd_intersect_chunk(l, reinterpret_cast<uint8_t const*>(x), out);
}

size_t fs_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_sparse_chunk(r, out);
}

size_t fd_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_dense_chunk(r, out);
}

size_t ff_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)r;
    return decode_full_chunk(l, out);
}

size_t pairwise_intersection(s_sequence const& l, s_sequence const& r,
                             uint32_t* out) {
    auto it_l = l.begin();
    auto it_r = r.begin();
    size_t size = 0;
    while (it_l.has_next() and it_r.has_next()) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):
                    n = ss_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = ds_intersect_chunk(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = fs_intersect_chunk(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = ds_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = dd_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = fd_intersect_chunk(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = fs_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::dense):
                    n = fd_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::full):
                    n = ff_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            uint32_t base = id_l << 16;
            for (size_t i = 0; i != n; ++i) {
                out[i] += base;
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