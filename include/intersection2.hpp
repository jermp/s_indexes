#pragma once

#include "constants.hpp"
#include "decode.hpp"
#include "uncompress.hpp"
#include "intersection.hpp"
// #include "intersect_vector16.hpp"

#include <algorithm>

namespace sliced {

// uint32_t decode_sparse_block(uint8_t const* begin, uint32_t base,
//                              uint16_t* out) {
//     uint32_t cardinality = *begin++;
//     // for (uint32_t i = 0; i != cardinality; ++i) {
//     //     out[i] = *begin + base;
//     //     ++begin;
//     // }
//     // return cardinality;

//     __m128i in_vec;
//     __m256i converted;
//     __m256i base_vec = _mm256_set1_epi16(base);

//     // replace _mm_load_si128 with _mm_lddqu_si128 ?
//     in_vec = _mm_lddqu_si128((__m128i const*)(begin + 0));
//     converted = _mm256_cvtepu8_epi16(in_vec);
//     converted = _mm256_add_epi16(base_vec, converted);
//     _mm256_storeu_si256((__m256i*)(out + 0), converted);

//     // most likely
//     if (cardinality <= 16) {
//         return cardinality;
//     }

//     in_vec = _mm_lddqu_si128((__m128i const*)(begin + 16));
//     converted = _mm256_cvtepu8_epi16(in_vec);
//     converted = _mm256_add_epi16(base_vec, converted);
//     _mm256_storeu_si256((__m256i*)(out + 16), converted);

//     return cardinality;
// }

// uint32_t decode_vector16(uint8_t const* begin, uint16_t* out) {
//     uint32_t num_blocks = *begin++;
//     uint16_t* tmp = out;
//     for (uint32_t i = 0; i != num_blocks; ++i) {
//         uint32_t k = *begin++;
//         uint32_t size = decode_sparse_block(begin, k * 256, tmp);
//         tmp += size;
//         begin += size + 1;
//     }
//     return tmp - out;
// }

void uncompress_sparse_blocks(uint8_t const* begin, uint64_t* bitmap) {
    uint32_t n = *begin++;
    for (uint32_t i = 0; i != n; ++i) {
        uint32_t b = *begin++ * 256;
        uint32_t c = *begin++;
        for (uint32_t i = 0; i != c; ++i, ++begin) {
            set_bit(*begin + b, bitmap);
        }
    }
}

uint8_t const* uncompress_dense_blocks(uint8_t const* begin, uint64_t* bitmap) {
    uint32_t n = *begin++;
    __m256i* out = reinterpret_cast<__m256i*>(bitmap);
    for (uint32_t i = 0; i != n; ++i) {
        uint32_t k = *begin++;
        __m256i block = _mm256_lddqu_si256((__m256i const*)begin);
        _mm256_storeu_si256(out + k, block);
        begin += 32;
    }
    return begin;
}

size_t ss_intersect_chunk2(uint8_t const* l, uint8_t const* r, uint32_t base,
                           uint64_t* bitmap1, uint64_t* bitmap2,
                           uint32_t* out) {
    l = uncompress_dense_blocks(l, bitmap1);
    uncompress_sparse_blocks(l, bitmap1);

    r = uncompress_dense_blocks(r, bitmap2);
    uncompress_sparse_blocks(r, bitmap2);

    size_t size = 0;
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        uint64_t w = bitmap1[i] & bitmap2[i];
        while (w != 0) {
            uint64_t t = w & -w;
            int r = __builtin_ctzll(w);
            out[size++] = i * 64 + r + base;
            w ^= t;
        }
        bitmap1[i] = 0;  // reset
        bitmap2[i] = 0;  // reset
    }
    return size;
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
                              uint64_t* bitmap1, uint64_t* bitmap2,
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
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):
                    n = ss_intersect_chunk2(it_l.data, it_r.data, base, bitmap1,
                                            bitmap2, out);
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