#pragma once

#include "immintrin.h"
#include "constants.hpp"
#include "decode.hpp"

namespace sliced {

uint32_t decode_sparse_block3(uint8_t const* begin, int cardinality,
                              uint32_t base, uint32_t* out) {
    // for (uint32_t i = 0; i != cardinality; ++i) {
    //     out[i] = *begin + base;
    //     ++begin;
    // }
    // return cardinality;

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

uint32_t decode_sparse_chunk3(uint8_t const* begin, int blocks, uint32_t base,
                              uint32_t* out) {
    assert(blocks >= 1 and blocks <= 256);
    uint8_t const* data = begin + blocks * 2;
    uint8_t const* end = data;
    uint32_t* tmp = out;

    while (begin != end) {
        uint8_t id = *begin;
        ++begin;
        int card = *begin;
        int type = TYPE_BY_CARDINALITY(card);

        uint32_t b = base + id * 256;
        uint32_t n = 0;

        if (type == type::sparse) {
            n = decode_sparse_block3(data, card, b, tmp);
        } else {
            n = decode_dense_block(data, b, tmp);
        }

        tmp += n;
        data += card;
        ++begin;
    }

    return size_t(tmp - out);
}

size_t s_sequence::decode3(uint32_t* out) {
    auto it = begin();
    uint32_t* in = out;
    for (uint32_t i = 0; i != chunks; ++i) {
        uint32_t n = 0;
        uint32_t base = it.id() << 16;
        switch (it.type()) {
            case type::sparse:
                n = decode_sparse_chunk3(it.data, it.blocks(), base, out);
                break;
            case type::dense:
                n = decode_dense_chunk(it.data, base, out);
                break;
            case type::full:
                n = decode_full_chunk(it.data, base, out);
                break;
            default:
                assert(false);
                __builtin_unreachable();
        }
        out += n;
        it.next();
    }
    return size_t(out - in);
}
}  // namespace sliced