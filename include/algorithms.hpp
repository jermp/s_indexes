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
    __m256i baseVec = _mm256_set1_epi32(-1);
    __m256i incVec = _mm256_set1_epi32(64);
    __m256i add8 = _mm256_set1_epi32(8);

    size_t decoded = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
        if (w == 0) {
            baseVec = _mm256_add_epi32(baseVec, incVec);
        } else {
            for (int k = 0; k < 4; ++k) {  // process 2 bytes of data at a time
                uint8_t byteA = (uint8_t)w;
                uint8_t byteB = (uint8_t)(w >> 8);
                w >>= 16;
                __m256i vecA = _mm256_load_si256(
                    (const __m256i*)tables::dictionary[byteA]);
                __m256i vecB = _mm256_load_si256(
                    (const __m256i*)tables::dictionary[byteB]);
                uint8_t advanceA = tables::size[byteA];
                uint8_t advanceB = tables::size[byteB];
                vecA = _mm256_add_epi32(baseVec, vecA);
                baseVec = _mm256_add_epi32(baseVec, add8);
                vecB = _mm256_add_epi32(baseVec, vecB);
                baseVec = _mm256_add_epi32(baseVec, add8);
                _mm256_storeu_si256((__m256i*)(out + decoded), vecA);
                decoded += advanceA;
                _mm256_storeu_si256((__m256i*)(out + decoded), vecB);
                decoded += advanceB;
            }
        }
    }

    begin += size_in_64bit_words * sizeof(uint64_t);
    return decoded;
}

uint32_t decode_sparse_block(uint8_t const* begin, uint32_t* out) {
    uint32_t cardinality = *begin++;
    // std::cout << "cardinality of sparse block: " << cardinality << std::endl;
    for (uint32_t i = 0; i != cardinality; ++i) {
        out[i] = *begin++;
    }
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
        // std::cout << int(header_byte) << std::endl;
        if (header_byte == 0) {
            base += 256 * 4;
        } else {
            for (uint32_t i = 0; i != 4; ++i) {
                uint8_t header = header_byte & 3;
                // std::cout << "header " << int(header) << std::endl;
                uint32_t d = 0;
                switch (header) {
                    case type::empty:
                        break;
                    case type::sparse:
                        // std::cout << "*data " << int(*data) << std::endl;
                        d = decode_sparse_block(data, tmp);
                        data += d + 1;
                        // std::cout << "*data " << int(*data) << std::endl;
                        break;
                    case type::dense:
                        d = decode_dense_block(data, tmp);
                        data += 32;
                        break;
                    case type::full:
                        d = decode_full_block(data, tmp);
                        break;
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

}  // namespace sliced