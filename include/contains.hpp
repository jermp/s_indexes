#pragma once

// #include "immintrin.h"

namespace sliced {

bool sparse_block_contains(uint8_t const* begin, int cardinality,
                           uint32_t value) {
    // scalar code as fast as SIMD approach
    for (int i = 0; i != cardinality; ++i) {
        if (begin[i] > value) {
            return false;
        }
        if (begin[i] == value) {
            return true;
        }
    }
    return false;

    // (void)cardinality;
    // __m256i c = _mm256_set1_epi8(value);
    // __m256i v = _mm256_loadu_si256((__m256i const*)begin);
    // __m256i res = _mm256_cmpeq_epi8(c, v);
    // return _mm256_testz_si256(res, _mm256_setzero_si256());
}

bool contains_sparse_chunk(uint8_t const* begin, int blocks, uint32_t value) {
    assert(blocks >= 1 and blocks <= 256);
    uint8_t const* data = begin + blocks * 2;
    uint8_t const* end = data;
    uint32_t block_id = value >> 8;

    while (begin != end) {
        uint8_t id = *begin;
        if (id > block_id) {
            return false;
        }
        int c = *(begin + 1) + 1;
        int bytes = 32;
        int type = type::dense;
        if (LIKELY(c < 31)) {
            bytes = c;
            type = type::sparse;
        }
        if (id == block_id) {
            uint32_t base = id * 256;
            assert(value >= base);
            value -= base;
            if (type == type::sparse) {
                return sparse_block_contains(data, c, value);
            } else {
                return bitmap_contains(reinterpret_cast<uint64_t const*>(data),
                                       value);
            }
        }
        data += bytes;
        begin += 2;
    }

    return false;
}

bool s_sequence::contains(uint32_t value) {
    auto it = begin();
    uint32_t chunk_id = value >> 16;
    it.skip_to_value(chunk_id);
    if (it.id() == chunk_id) {
        value &= 0xFFFF;
        switch (it.type()) {
            case type::sparse:
                return contains_sparse_chunk(it.data, it.blocks(), value);
            case type::dense:
                return bitmap_contains(
                    reinterpret_cast<uint64_t const*>(it.data), value);
            case type::full:
                return true;
            default:
                assert(false);
                __builtin_unreachable();
        }
    }
    return false;
}

}  // namespace sliced