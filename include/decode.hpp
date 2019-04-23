#pragma once

#include "immintrin.h"

#include "configuration.hpp"
#include "tables.hpp"

namespace sliced {

uint32_t decode_bitmap(uint8_t const* begin, size_t size_in_64bit_words,
                       uint32_t* out) {
    // code adapted from:
    // https://lemire.me/blog/2018/03/08/iterating-over-set-bits-quickly-simd-edition/
    // credits to Daniel Lemire
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(begin);
    __m256i base_vec = _mm256_set1_epi32(-1);
    __m256i inc_vec = _mm256_set1_epi32(64);
    __m256i add8 = _mm256_set1_epi32(8);

    size_t decoded = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
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

    begin += size_in_64bit_words * sizeof(uint64_t);
    return decoded;
}

uint32_t decode_sparse_block(uint8_t const* begin, uint32_t* out) {
    uint32_t cardinality = *begin++;

    // for (uint32_t i = 0; i != cardinality; ++i) {
    //     out[i] = *begin++;
    // }

    // for (size_t i = 0; i < cardinality; i += 8) {
    //     __m128i in_vec = _mm_load_si128((__m128i const*)begin);
    //     __m256i converted = _mm256_cvtepu8_epi32(in_vec);
    //     _mm256_storeu_si256((__m256i*)(out + i), converted);
    //     begin += 8;
    // }

    __m128i in_vec;
    __m256i converted;

    in_vec = _mm_load_si128((__m128i const*)(begin + 0));
    converted = _mm256_cvtepu8_epi32(in_vec);
    _mm256_storeu_si256((__m256i*)(out + 0), converted);

    if (cardinality <= 8) {  // most likely
        return cardinality;
    }

    in_vec = _mm_load_si128((__m128i const*)(begin + 8));
    converted = _mm256_cvtepu8_epi32(in_vec);
    _mm256_storeu_si256((__m256i*)(out + 8), converted);

    in_vec = _mm_load_si128((__m128i const*)(begin + 16));
    converted = _mm256_cvtepu8_epi32(in_vec);
    _mm256_storeu_si256((__m256i*)(out + 16), converted);

    in_vec = _mm_load_si128((__m128i const*)(begin + 24));
    converted = _mm256_cvtepu8_epi32(in_vec);
    _mm256_storeu_si256((__m256i*)(out + 24), converted);

    return cardinality;
}

uint32_t decode_dense_block(uint8_t const* begin, uint32_t* out) {
    return decode_bitmap(begin, constants::block_size / 64, out);
}

uint32_t decode_full_block(uint8_t const* begin, uint32_t* out) {
    (void)begin;
    for (uint32_t i = 0; i != constants::block_size; ++i) {
        out[i] = i;
    }
    return constants::block_size;
}

uint32_t decode_sparse_chunk(uint8_t const* begin, uint32_t* out) {
    uint8_t const* data = begin + 64;
    uint32_t* tmp = out;
    uint32_t base = 0;
    uint32_t decoded = 0;
    for (uint32_t i = 0; i != 64; ++i) {
        uint8_t header_byte = begin[i];
        if (header_byte == 0) {
            base += 256 * 4;
        } else {
            for (uint32_t i = 0; i != 4; ++i) {
                uint8_t header = header_byte & 3;
                uint32_t d = 0;
                switch (header) {
                    case type::empty:
                        break;
                    case type::sparse:
                        d = decode_sparse_block(data, tmp);
                        data += d + 1;
                        break;
                    case type::dense:
                        d = decode_dense_block(data, tmp);
                        data += 32;
                        break;
                    case type::full:
                        d = decode_full_block(data, tmp);
                        break;
                    default:
                        assert(false);
                        __builtin_unreachable();
                }

                for (size_t i = 0; i != d; ++i) {
                    tmp[i] += base;
                }

                tmp += d;
                base += 256;
                decoded += d;
                header_byte >>= 2;
            }
        }
    }
    return decoded;
}

uint32_t decode_dense_chunk(uint8_t const* begin, uint32_t* out) {
    return decode_bitmap(begin, constants::chunk_size / 64, out);
}

uint32_t decode_full_chunk(uint8_t const* begin, uint32_t* out) {
    (void)begin;
    for (uint32_t i = 0; i != constants::chunk_size; ++i) {
        out[i] = i;
    }
    return constants::chunk_size;
}

size_t s_sequence::decode(uint32_t* out) {
    auto h = header();
    auto d = data();
    size_t decoded = 0;

    for (uint32_t i = 0; i != chunks; ++i) {
        uint16_t id = *h;
        uint16_t type = *(h + 1);
        uint16_t offset = *(h + 2);

        uint32_t n = 0;
        switch (type) {
            case type::sparse:
                n = decode_sparse_chunk(d, out);
                break;
            case type::dense:
                n = decode_dense_chunk(d, out);
                break;
            case type::full:
                n = decode_full_chunk(d, out);
                break;
            default:
                assert(false);
                __builtin_unreachable();
        }

        // same speed as with SIMD (vectorization at compile time)
        uint32_t base = id << 16;
        for (size_t i = 0; i != n; ++i) {
            out[i] += base;
        }

        // __m256i base_vec = _mm256_set1_epi32(base);
        // size_t k = (n + 7) / 8 * 8;
        // for (size_t i = 0; i != k; i += 8) {
        //     __m256i in_vec = _mm256_load_si256((__m256i const*)(out +
        //     i)); in_vec = _mm256_add_epi32(base_vec, in_vec);
        //     _mm256_storeu_si256((__m256i*)(out + i), in_vec);
        // }

        out += n;
        decoded += n;
        d += offset;
        h += 3;
    }

    assert(decoded > 0);
    return decoded;
}
}  // namespace sliced