#pragma once

#include "immintrin.h"
#include "constants.hpp"
#include "decode.hpp"

namespace sliced {

inline uint32_t decode_bitmap(uint8_t const* begin, size_t size_in_64bit_words,
                              uint32_t base, uint32_t* out) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(begin);
    uint32_t size = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
        while (w != 0) {
            uint64_t t = w & (~w + 1);
            int r = __builtin_ctzll(w);
            out[size++] = r + base;
            w ^= t;
        }
        base += 64;
    }
    return size;
}

uint32_t decode_sparse_block(uint8_t const* begin, int cardinality,
                             uint32_t base, uint32_t* out) {
    __m128i in_vec;
    __m256i converted;
    __m256i base_vec = _mm256_set1_epi32(base);

    in_vec = _mm_lddqu_si128((__m128i const*)(begin + 0));
    converted = _mm256_cvtepu8_epi32(in_vec);
    converted = _mm256_add_epi32(base_vec, converted);
    _mm256_storeu_si256((__m256i*)(out + 0), converted);

    // most likely
    if (cardinality <= 8) {
        return cardinality;
    }

    in_vec = _mm_lddqu_si128((__m128i const*)(begin + 8));
    converted = _mm256_cvtepu8_epi32(in_vec);
    converted = _mm256_add_epi32(base_vec, converted);
    _mm256_storeu_si256((__m256i*)(out + 8), converted);

    in_vec = _mm_lddqu_si128((__m128i const*)(begin + 16));
    converted = _mm256_cvtepu8_epi32(in_vec);
    converted = _mm256_add_epi32(base_vec, converted);
    _mm256_storeu_si256((__m256i*)(out + 16), converted);

    in_vec = _mm_lddqu_si128((__m128i const*)(begin + 24));
    converted = _mm256_cvtepu8_epi32(in_vec);
    converted = _mm256_add_epi32(base_vec, converted);
    _mm256_storeu_si256((__m256i*)(out + 24), converted);

    return cardinality;
}

uint32_t decode_sparse_chunk(uint8_t const* begin, int blocks, uint32_t base,
                             uint32_t* out) {
    assert(blocks >= 1 and blocks <= 256);
    uint8_t const* data = begin + blocks * 2;
    uint8_t const* end = data;
    uint32_t* tmp = out;
    while (begin != end) {
        uint8_t id = *begin;
        int c = *(begin + 1) + 1;
        int bytes = 32;
        int type = type::dense;
        if (LIKELY(c < 31)) {
            bytes = c;
            type = type::sparse;
        }
        uint32_t b = base + id * 256;
        if (type == type::sparse) {
            tmp += decode_sparse_block(data, c, b, tmp);
        } else {
            tmp += decode_bitmap(data, constants::block_size_in_64bit_words, b,
                                 tmp);
        }
        data += bytes;
        begin += 2;
    }
    return size_t(tmp - out);
}

inline uint32_t decode_full_chunk(uint32_t base, uint32_t* out) {
    for (uint32_t i = 0; i != constants::chunk_size; ++i) {
        out[i] = i + base;
    }
    return constants::chunk_size;
}

size_t decode_chunk(s_sequence::iterator const& it, uint32_t* out) {
    uint32_t base = it.id() << 16;
    switch (it.type()) {
        case type::sparse:
            return decode_sparse_chunk(it.data, it.blocks(), base, out);
        case type::dense:
            return decode_bitmap(it.data, constants::chunk_size_in_64bit_words,
                                 base, out);
        case type::full:
            return decode_full_chunk(base, out);
        default:
            assert(false);
            __builtin_unreachable();
    }
}

size_t s_sequence::decode(uint32_t* out) const {
    auto it = begin();
    uint32_t* in = out;
    for (uint32_t i = 0; i != chunks; ++i) {
        out += decode_chunk(it, out);
        it.next();
    }
    return size_t(out - in);
}
}  // namespace sliced