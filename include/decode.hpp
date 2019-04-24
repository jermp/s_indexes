#pragma once

#include "immintrin.h"
#include "configuration.hpp"

namespace sliced {

uint32_t decode_bitmap(uint8_t const* begin, size_t size_in_64bit_words,
                       uint32_t* out) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(begin);
    uint32_t pos = 0;
    uint64_t bitset;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        bitset = bitmap[i];
        while (bitset != 0) {
            uint64_t t = bitset & -bitset;
            int r = __builtin_ctzll(bitset);
            out[pos++] = i * 64 + r;
            bitset ^= t;
        }
    }
    return pos;
}

uint32_t decode_sparse_block(uint8_t const* begin, uint32_t* out) {
    uint32_t cardinality = *begin++;
    __m128i in_vec;
    __m256i converted;

    in_vec = _mm_load_si128((__m128i const*)(begin + 0));
    converted = _mm256_cvtepu8_epi32(in_vec);
    _mm256_storeu_si256((__m256i*)(out + 0), converted);

    // if (cardinality <= 8) {  // most likely
    //     return cardinality;
    // }

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
    return decode_bitmap(begin, constants::block_size_in_64bit_words, out);
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
    return decode_bitmap(begin, constants::chunk_size_in_64bit_words, out);
}

uint32_t decode_full_chunk(uint8_t const* begin, uint32_t* out) {
    (void)begin;
    for (uint32_t i = 0; i != constants::chunk_size; ++i) {
        out[i] = i;
    }
    return constants::chunk_size;
}

size_t s_sequence::decode(uint32_t* out) {
    auto it = begin();
    size_t decoded = 0;
    for (uint32_t i = 0; i != chunks; ++i) {
        uint16_t id = it.id();
        uint32_t n = 0;
        switch (it.type()) {
            case type::sparse:
                n = decode_sparse_chunk(it.data, out);
                break;
            case type::dense:
                n = decode_dense_chunk(it.data, out);
                break;
            case type::full:
                n = decode_full_chunk(it.data, out);
                break;
            default:
                assert(false);
                __builtin_unreachable();
        }
        uint32_t base = id << 16;
        for (size_t i = 0; i != n; ++i) {
            out[i] += base;
        }
        out += n;
        decoded += n;
        it.next();
    }
    assert(decoded > 0);
    return decoded;
}
}  // namespace sliced