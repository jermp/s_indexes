#pragma once

#include "configuration.hpp"
#include "decode.hpp"

#define chunk_pair(l, r) (3 * (l) + (r))

namespace sliced {

size_t intersect_sparse_sparse(uint8_t const* l, uint8_t const* r,
                               uint32_t* out) {
    // todo
}

size_t intersect_dense_sparse(uint8_t const* l, uint8_t const* r,
                              uint32_t* out) {
    // todo
}

size_t intersect_full_sparse(uint8_t const* l, uint8_t const* r,
                             uint32_t* out) {
    (void)l;
    return decode_sparse_chunk(r, out);
}

size_t intersect_full_dense(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_dense_chunk(r, out);
}

size_t intersect_dense_dense(uint8_t const* l, uint8_t const* r,
                             uint32_t* out) {
    uint64_t const* bitmap_l = reinterpret_cast<uint64_t const*>(l);
    uint64_t const* bitmap_r = reinterpret_cast<uint64_t const*>(r);
    __m256i base_vec = _mm256_set1_epi32(-1);
    __m256i inc_vec = _mm256_set1_epi32(64);
    __m256i add8 = _mm256_set1_epi32(8);

    size_t decoded = 0;
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
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

size_t intersect_full_full(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)r;
    return decode_full_chunk(l, out);
}

size_t pairwise_intersection(s_sequence const& l, s_sequence const& r,
                             uint32_t* out) {
    iterator it_l = l.begin();
    iterator it_r = r.begin();
    size_t size = 0;

    while (it_l.has_next() and it_r.has_next()) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):
                    n = intersect_sparse_sparse(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = intersect_dense_sparse(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = intersect_full_sparse(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = intersect_dense_sparse(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = intersect_dense_dense(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = intersect_full_dense(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = intersect_full_sparse(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::dense):
                    n = intersect_full_dense(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::full):
                    n = intersect_full_full(it_l.data, it_r.data, out);
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