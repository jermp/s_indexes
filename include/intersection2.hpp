#pragma once

#include "constants.hpp"
#include "decode.hpp"
#include "uncompress.hpp"
#include "intersection.hpp"
#include "intersect_vector16.hpp"

namespace sliced {

uint32_t decode_sparse_block(uint8_t const* begin, uint32_t base,
                             uint16_t* out) {
    uint32_t cardinality = *begin++;
    // for (uint32_t i = 0; i != cardinality; ++i) {
    //     out[i] = *begin + base;
    //     ++begin;
    // }
    // return cardinality;

    __m128i in_vec;
    __m256i converted;
    __m256i base_vec = _mm256_set1_epi16(base);

    in_vec = _mm_load_si128((__m128i const*)(begin + 0));
    converted = _mm256_cvtepu8_epi16(in_vec);
    converted = _mm256_add_epi32(base_vec, converted);
    _mm256_storeu_si256((__m256i*)(out + 0), converted);

    // most likely
    if (cardinality <= 16) {
        return cardinality;
    }

    in_vec = _mm_load_si128((__m128i const*)(begin + 16));
    converted = _mm256_cvtepu8_epi32(in_vec);
    converted = _mm256_add_epi32(base_vec, converted);
    _mm256_storeu_si256((__m256i*)(out + 16), converted);

    return cardinality;
}

uint32_t decode_vector16(uint8_t const* begin, uint16_t* out) {
    uint32_t num_blocks = *begin++;
    uint16_t* initout = out;
    for (uint32_t i = 0; i != num_blocks; ++i) {
        uint32_t size = decode_sparse_block(begin + 1, *begin * 256, out);
        out += size;
    }
    return out - initout;
}

void uncompress(uint8_t const* begin, uint32_t n, uint64_t* bitmap) {
    __m256i* out = reinterpret_cast<__m256i*>(bitmap);
    __m256i block;
    for (uint32_t i = 0; i != n; ++i) {
        uint32_t k = *begin++;
        block = _mm256_load_si256((__m256i const*)begin);
        _mm256_storeu_si256(out + k, block);
    }
}

void and_bit(uint16_t pos, uint64_t* bitmap) {
    uint64_t word = bitmap[pos >> 6];
    word &= uint64_t(1) << pos;
}

size_t decode_and_reset_bitmap(uint64_t* bitmap, uint32_t base, uint32_t* out) {
    size_t size = 0;
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
        while (w != 0) {
            uint64_t t = w & -w;
            int r = __builtin_ctzll(w);
            out[size++] = i * 64 + r + base;
            w ^= t;
        }
        bitmap[i] = 0;  // reset
    }
    return size;
}

size_t ss_intersect_chunk2(uint8_t const* l, uint8_t const* r, uint32_t base,
                           uint16_t* b1, uint16_t* b2, uint16_t* b3,
                           uint64_t* bitmap, uint32_t* out) {
    /*

    1. decode sparse blocks of c1 into b1;
    2. decode sparse blocks of c2 into b2;
    3. intersect b1 and b2 into b3;
    4. uncompress dense blocks of c1 into bitmap;
    5. for every dense block of c2, compute AND with the corresponding block of
    bitmap;
    6. for every element p of b3, AND bit in position p  of bitmap with 1;
    7. decode and reset bitmap into out.

    */

    uint32_t dense_blocks_l = *l++;
    uint32_t dense_blocks_r = *r++;
    uint32_t size_b1 = decode_vector16(l + dense_blocks_l * (1 + 32), b1);
    uint32_t size_b2 = decode_vector16(r + dense_blocks_r * (1 + 32), b2);

    uint32_t size_b3 = intersect_vector16(b1, size_b1, b2, size_b2, b3);

    uncompress(l, dense_blocks_l, bitmap);

    __m256i* bitmap_256 = reinterpret_cast<__m256i*>(bitmap);
    for (uint32_t i = 0; i != dense_blocks_r; ++i) {
        uint32_t k = *r++;
        __m256i block = _mm256_and_si256(*(bitmap_256 + k),
                                         _mm256_load_si256((__m256i const*)r));
        _mm256_storeu_si256(bitmap_256 + k, block);
    }

    for (uint32_t i = 0; i != size_b3; ++i) {
        and_bit(b3[i], bitmap);
    }

    return decode_and_reset_bitmap(bitmap, base, out);
}

// size_t ds_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
//                           uint32_t* out) {
//     static uint64_t x[1024];
//     std::fill(x, x + 1024, 0);
//     uncompress_sparse_chunk(r, x);
//     return dd_intersect_chunk(l, reinterpret_cast<uint8_t const*>(x), base,
//                               out);
// }

// size_t fs_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
//                           uint32_t* out) {
//     (void)l;
//     return decode_sparse_chunk(r, base, out);
// }

size_t pairwise_intersection2(s_sequence const& l, s_sequence const& r,
                              uint16_t* b1, uint16_t* b2, uint16_t* b3,
                              uint64_t* bitmap, uint32_t* out) {
    auto it_l = l.begin();
    auto it_r = r.begin();
    size_t size = 0;
    while (it_l.has_next() and it_r.has_next()) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            uint32_t base = id_l << 16;
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):
                    n = ss_intersect_chunk2(it_l.data, it_r.data, base, b1, b2,
                                            b3, bitmap, out);
                    break;
                case chunk_pair(type::sparse, type::dense):
                    // n = ds_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    // n = fs_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    // n = ds_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = dd_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = fd_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    // n = fs_intersect_chunk(it_l.data, it_r.data, base, out);
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