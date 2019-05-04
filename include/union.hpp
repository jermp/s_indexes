#pragma once

#include "immintrin.h"

#include "constants.hpp"
#include "util.hpp"
#include "uncompress.hpp"
#include "decode.hpp"
#include "table1.hpp"

namespace sliced {

#define DECODE(ptr)                                               \
    uint8_t id = *ptr;                                            \
    int bytes = *(ptr + 1);                                       \
    out += decode_block(data_##ptr, bytes, base + id * 256, out); \
    data_##ptr += bytes;                                          \
    ptr += 2;

void fill(uint8_t const* in, __m128i* out, int cardinality) {
    assert(cardinality > 0);
    switch (cardinality) {
        case 1:
            *out =
                _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                             0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, in[0]);
            break;
        case 2:
            *out =
                _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                             0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, in[1], in[0]);
            break;
        case 3:
            *out =
                _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                             0xFF, 0xFF, 0xFF, 0xFF, 0xFF, in[2], in[1], in[0]);
            break;
        case 4:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                0xFF, 0xFF, 0xFF, 0xFF, in[3], in[2], in[1],
                                in[0]);
            break;
        case 5:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                0xFF, 0xFF, 0xFF, in[4], in[3], in[2], in[1],
                                in[0]);
            break;
        case 6:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                0xFF, 0xFF, in[5], in[4], in[3], in[2], in[1],
                                in[0]);
            break;
        case 7:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                0xFF, in[6], in[5], in[4], in[3], in[2], in[1],
                                in[0]);
            break;
        case 8:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                in[7], in[6], in[5], in[4], in[3], in[2], in[1],
                                in[0]);
            break;
        case 9:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, in[8],
                                in[7], in[6], in[5], in[4], in[3], in[2], in[1],
                                in[0]);
            break;
        case 10:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, in[9],
                                in[8], in[7], in[6], in[5], in[4], in[3], in[2],
                                in[1], in[0]);
            break;
        case 11:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, in[10], in[9],
                                in[8], in[7], in[6], in[5], in[4], in[3], in[2],
                                in[1], in[0]);
            break;
        case 12:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, 0xFF, in[11], in[10], in[9],
                                in[8], in[7], in[6], in[5], in[4], in[3], in[2],
                                in[1], in[0]);
            break;
        case 13:
            *out = _mm_set_epi8(0xFF, 0xFF, 0xFF, in[12], in[11], in[10], in[9],
                                in[8], in[7], in[6], in[5], in[4], in[3], in[2],
                                in[1], in[0]);
            break;
        case 14:
            *out = _mm_set_epi8(0xFF, 0xFF, in[13], in[12], in[11], in[10],
                                in[9], in[8], in[7], in[6], in[5], in[4], in[3],
                                in[2], in[1], in[0]);
            break;
        case 15:
            *out = _mm_set_epi8(0xFF, in[14], in[13], in[12], in[11], in[10],
                                in[9], in[8], in[7], in[6], in[5], in[4], in[3],
                                in[2], in[1], in[0]);
            break;
        case 16:
            *out = _mm_set_epi8(in[15], in[14], in[13], in[12], in[11], in[10],
                                in[9], in[8], in[7], in[6], in[5], in[4], in[3],
                                in[2], in[1], in[0]);
            break;
        default:
            assert(false);
            __builtin_unreachable();
    }
}

int store_unique(__m128i const* old, __m128i* newval, __m256i const* base_v,
                 uint32_t* out) {
    __m128i vecTmp = _mm_alignr_epi8(*newval, *old, 15);
    int M = _mm_movemask_epi8(_mm_cmpeq_epi8(vecTmp, *newval));
    int n = 16 - _mm_popcnt_u32(M);
    __m128i key = _mm_lddqu_si128((const __m128i*)shuffle_mask1 + M);
    __m128i val = _mm_shuffle_epi8(*newval, key);
    __m256i converted_v = _mm256_cvtepu8_epi32(val);
    converted_v = _mm256_add_epi32(*base_v, converted_v);
    _mm256_storeu_si256((__m256i*)out, converted_v);
    if (n > 8) {
        val = _mm_bsrli_si128(val, 8);
        converted_v = _mm256_cvtepu8_epi32(val);
        converted_v = _mm256_add_epi32(*base_v, converted_v);
        _mm256_storeu_si256((__m256i*)(out + 8), converted_v);
    }

    return n;
}

void sse_merge(__m128i const* vInput1, __m128i const* vInput2, __m128i* vecMin,
               __m128i* vecMax) {
    __m128i vecTmp;
    vecTmp = _mm_min_epu8(*vInput1, *vInput2);
    *vecMax = _mm_max_epu8(*vInput1, *vInput2);

    vecTmp = _mm_alignr_epi8(vecTmp, vecTmp, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    vecTmp = _mm_alignr_epi8(*vecMin, *vecMin, 1);
    *vecMin = _mm_min_epu8(vecTmp, *vecMax);
    *vecMax = _mm_max_epu8(vecTmp, *vecMax);

    *vecMin = _mm_alignr_epi8(*vecMin, *vecMin, 1);
}

// void print_sse8(__m128i const* reg) {
//     for (int i = 0; i != 16; ++i) {
//         std::cout << _mm_extract_epi8(*reg, i) << " ";
//     }
//     std::cout << std::endl;
// }

size_t ss_union_block(uint8_t const* l, uint8_t const* r, int card_l,
                      int card_r, uint32_t base, uint32_t* out) {
    assert(card_l > 0 and
           card_l <= int(constants::block_sparseness_threshold - 2));
    assert(card_r > 0 and
           card_r <= int(constants::block_sparseness_threshold - 2));
    size_t size = 0;

    if (LIKELY(card_l <= 16 and card_r <= 16)) {
        bool last = l[card_l - 1] == 255 or r[card_r - 1] == 255;

        __m128i v_l;
        __m128i v_r;
        __m128i laststore;

        fill(l, &v_l, card_l);
        fill(r, &v_r, card_r);
        // std::cout << "l and r:" << std::endl;
        // print_sse8(&v_l);
        // print_sse8(&v_r);

        __m128i min_v;
        __m128i max_v;
        sse_merge(&v_l, &v_r, &min_v, &max_v);
        // std::cout << "min and max:" << std::endl;
        // print_sse8(&min_v);
        // print_sse8(&max_v);

        laststore = _mm_set1_epi8(-1);
        __m256i base_v = _mm256_set1_epi32(base);
        size += store_unique(&laststore, &min_v, &base_v, out);
        out += size;
        laststore = min_v;
        size += store_unique(&laststore, &max_v, &base_v, out);

        return size - !last;
    }

    uint8_t const* end_l = l + card_l;
    uint8_t const* end_r = r + card_r;

    while (true) {
        if (*l < *r) {
            out[size++] = *l + base;
            ++l;
            if (l == end_l) {
                break;
            }
        } else if (*r < *l) {
            out[size++] = *r + base;
            ++r;
            if (r == end_r) {
                break;
            }
        } else {
            out[size++] = *l + base;
            ++l;
            ++r;
            if (l == end_l or r == end_r) {
                break;
            }
        }
    }

    if (l != end_l) {
        size += decode_sparse_block(l, end_l - l, base, out + size);
    }

    if (r != end_l) {
        size += decode_sparse_block(r, end_r - r, base, out + size);
    }

    return size;
}

size_t ds_union_block(uint8_t const* l, uint8_t const* r, int cardinality,
                      uint32_t base, uint32_t* out) {
    static uint64_t x[4];
    memcpy(x, reinterpret_cast<uint64_t const*>(l), constants::block_size / 8);
    uncompress_sparse_block(r, cardinality, x);
    return or_bitmaps(l, reinterpret_cast<uint8_t const*>(x),
                      constants::block_size_in_64bit_words, base, out);
}

inline uint32_t decode_block(uint8_t const* data, int bytes, uint32_t base,
                             uint32_t* out) {
    int type = TYPE_BY_BYTES(bytes);
    if (type == type::sparse) {
        return decode_sparse_block(data, bytes, base, out);
    }
    return decode_bitmap(data, constants::block_size_in_64bit_words, base, out);
}

size_t ss_union_chunk(uint8_t const* l, uint8_t const* r, int blocks_l,
                      int blocks_r, uint32_t base, uint32_t* out) {
    assert(blocks_l >= 1 and blocks_l <= 256);
    assert(blocks_r >= 1 and blocks_r <= 256);

    uint8_t const* data_l = l + blocks_l * 2;
    uint8_t const* data_r = r + blocks_r * 2;
    uint8_t const* end_l = data_l;
    uint8_t const* end_r = data_r;
    uint32_t* in = out;

    while (true) {
        if (*l < *r) {
            DECODE(l)
            if (l == end_l) {
                break;
            }
        } else if (*l > *r) {
            DECODE(r)
            if (r == end_r) {
                break;
            }
        } else {
            uint8_t id = *l;
            ++l;
            ++r;
            int bytes_l = *l;
            int bytes_r = *r;
            int type_l = TYPE_BY_BYTES(bytes_l);
            int type_r = TYPE_BY_BYTES(bytes_r);

            uint32_t b = base + id * 256;
            uint32_t n = 0;

            switch (block_pair(type_l, type_r)) {
                case block_pair(type::sparse, type::sparse):
                    n = ss_union_block(data_l, data_r, bytes_l, bytes_r, b,
                                       out);
                    break;
                case block_pair(type::sparse, type::dense):
                    n = ds_union_block(data_r, data_l, bytes_l, b, out);
                    break;
                case block_pair(type::dense, type::sparse):
                    n = ds_union_block(data_l, data_r, bytes_r, b, out);
                    break;
                case block_pair(type::dense, type::dense):
                    n = or_bitmaps(data_l, data_r,
                                   constants::block_size_in_64bit_words, b,
                                   out);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            out += n;
            data_l += bytes_l;
            data_r += bytes_r;
            ++l;
            ++r;

            if (l == end_l or r == end_r) {
                break;
            }
        }
    }

    while (l != end_l) {
        DECODE(l)
    }

    while (r != end_r) {
        DECODE(r)
    }

    return size_t(out - in);
}

size_t ds_union_chunk(uint8_t const* l, uint8_t const* r, int blocks_r,
                      uint32_t base, uint32_t* out) {
    static std::vector<uint64_t> x(1024);
    std::fill(x.begin(), x.end(), 0);
    uncompress_sparse_chunk(r, blocks_r, x.data());
    return or_bitmaps(l, reinterpret_cast<uint8_t const*>(x.data()),
                      constants::chunk_size_in_64bit_words, base, out);
}

size_t pairwise_union(s_sequence const& l, s_sequence const& r, uint32_t* out) {
    auto it_l = l.begin();
    auto it_r = r.begin();
    uint32_t* in = out;

    while (true) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            uint32_t base = id_l << 16;
            int blocks_l = 0;
            int blocks_r = 0;

            uint16_t type_l = it_l.type();
            uint16_t type_r = it_r.type();

            switch (chunk_pair(type_l, type_r)) {
                case chunk_pair(type::sparse, type::sparse):
                    blocks_l = it_l.blocks();
                    blocks_r = it_r.blocks();
                    if (blocks_l < blocks_r) {
                        n = ss_union_chunk(it_l.data, it_r.data, blocks_l,
                                           blocks_r, base, out);
                    } else {
                        n = ss_union_chunk(it_r.data, it_l.data, blocks_r,
                                           blocks_l, base, out);
                    }
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = ds_union_chunk(it_r.data, it_l.data, it_l.blocks(),
                                       base, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = ds_union_chunk(it_l.data, it_r.data, it_r.blocks(),
                                       base, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = or_bitmaps(it_l.data, it_r.data,
                                   constants::chunk_size_in_64bit_words, base,
                                   out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::full, type::dense):
                    n = decode_full_chunk(base, out);
                    break;
                case chunk_pair(type::full, type::full):
                    n = decode_full_chunk(base, out);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            out += n;

            it_l.next();
            it_r.next();
            if (!it_l.has_next() or !it_r.has_next()) {
                break;
            }

        } else if (id_l < id_r) {
            out += decode_chunk(it_l, out);
            it_l.next();
            if (!it_l.has_next()) {
                break;
            }
        } else {
            out += decode_chunk(it_r, out);
            it_r.next();
            if (!it_r.has_next()) {
                break;
            }
        }
    }

    while (it_l.has_next()) {
        out += decode_chunk(it_l, out);
        it_l.next();
    }

    while (it_r.has_next()) {
        out += decode_chunk(it_r, out);
        it_r.next();
    }

    return size_t(out - in);
}

}  // namespace sliced