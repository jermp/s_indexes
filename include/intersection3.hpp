#pragma once

#include "constants.hpp"
#include "decode3.hpp"
#include "uncompress3.hpp"

#include "table.hpp"
#include "intersect_vector16.hpp"

#define chunk_pair(l, r) (3 * (l) + (r))
#define block_pair(l, r) (2 * (l) + (r))

namespace sliced {

size_t ss_intersect_block3(uint8_t const* l, uint8_t const* r, int card_l,
                           int card_r, uint32_t base, uint32_t* out) {
    assert(card_l > 0 and
           card_l <= int(constants::block_sparseness_threshold - 2));
    assert(card_r > 0 and
           card_r <= int(constants::block_sparseness_threshold - 2));
    size_t size = 0;

    // card_l <= 16 and card_r <= 16 -> 1 cmpestr
    if (LIKELY(card_l <= 16 and card_r <= 16)) {
        __m256i base_v = _mm256_set1_epi32(base);
        __m128i v_l = _mm_lddqu_si128((__m128i const*)l);
        __m128i v_r = _mm_lddqu_si128((__m128i const*)r);
        __m256i converted_v;
        __m128i sm16;
        __m128i p;

        __m128i res = _mm_cmpestrm(
            v_l, card_l, v_r, card_r,
            _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
        int mask = _mm_extract_epi32(res, 0);
        size = _mm_popcnt_u32(mask);
        assert(size <= 16);

        sm16 = _mm_load_si128((__m128i const*)shuffle_mask + mask);
        p = _mm_shuffle_epi8(v_r, sm16);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)out, converted_v);

        p = _mm_bsrli_si128(p, 8);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)(out + 8), converted_v);

        return size;
    }

    // card_l <= 16 and card_r  > 16 -> 2 cmpestr
    if (card_l <= 16 and card_r > 16) {
        __m256i base_v = _mm256_set1_epi32(base);
        __m128i v_l = _mm_lddqu_si128((__m128i const*)l);
        __m128i v_r = _mm_lddqu_si128((__m128i const*)r);
        __m256i converted_v;
        __m128i sm16;
        __m128i p;
        __m128i res;

        res = _mm_cmpestrm(
            v_l, card_l, v_r, card_r,
            _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
        int mask = _mm_extract_epi32(res, 0);
        size = _mm_popcnt_u32(mask);

        sm16 = _mm_load_si128((__m128i const*)shuffle_mask + mask);
        p = _mm_shuffle_epi8(v_r, sm16);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)out, converted_v);

        p = _mm_bsrli_si128(p, 8);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)(out + 8), converted_v);

        out += size;
        r += 16;
        v_r = _mm_lddqu_si128((__m128i const*)r);
        card_r -= 16;

        res = _mm_cmpestrm(
            v_l, card_l, v_r, card_r,
            _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
        mask = _mm_extract_epi32(res, 0);
        size += _mm_popcnt_u32(mask);

        sm16 = _mm_load_si128((__m128i const*)shuffle_mask + mask);
        p = _mm_shuffle_epi8(v_r, sm16);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)out, converted_v);

        p = _mm_bsrli_si128(p, 8);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)(out + 8), converted_v);

        return size;
    }

    // card_r <= 16 and card_l  > 16 -> 2 cmpestr
    if (card_r <= 16 and card_l > 16) {
        __m256i base_v = _mm256_set1_epi32(base);
        __m128i v_l = _mm_lddqu_si128((__m128i const*)l);
        __m128i v_r = _mm_lddqu_si128((__m128i const*)r);
        __m256i converted_v;
        __m128i sm16;
        __m128i p;
        __m128i res;

        res = _mm_cmpestrm(
            v_l, card_l, v_r, card_r,
            _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
        int mask = _mm_extract_epi32(res, 0);
        size = _mm_popcnt_u32(mask);

        sm16 = _mm_load_si128((__m128i const*)shuffle_mask + mask);
        p = _mm_shuffle_epi8(v_r, sm16);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)out, converted_v);

        p = _mm_bsrli_si128(p, 8);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)(out + 8), converted_v);

        out += size;
        l += 16;
        v_l = _mm_lddqu_si128((__m128i const*)l);
        card_l -= 16;

        res = _mm_cmpestrm(
            v_l, card_l, v_r, card_r,
            _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK);
        mask = _mm_extract_epi32(res, 0);
        size += _mm_popcnt_u32(mask);

        sm16 = _mm_load_si128((__m128i const*)shuffle_mask + mask);
        p = _mm_shuffle_epi8(v_r, sm16);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)out, converted_v);

        p = _mm_bsrli_si128(p, 8);

        converted_v = _mm256_cvtepu8_epi32(p);
        converted_v = _mm256_add_epi32(base_v, converted_v);
        _mm256_storeu_si256((__m256i*)(out + 8), converted_v);

        return size;
    }

    // card_l  > 16 and card_r  > 16 -> 4 cmpestr, but scalar may be more
    // convenient...

    uint8_t const* end_l = l + card_l;
    uint8_t const* end_r = r + card_r;
    while (true) {
        while (*l < *r) {
            if (++l == end_l) {
                return size;
            }
        }
        while (*l > *r) {
            if (++r == end_r) {
                return size;
            }
        }
        if (*l == *r) {
            out[size++] = *l + base;
            if (++l == end_l or ++r == end_r) {
                return size;
            }
        }
    }

    return size;
}

size_t ds_intersect_block3(uint8_t const* l, uint8_t const* r, int card,
                           uint32_t base, uint32_t* out) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(l);
    uint32_t k = 0;
    for (int i = 0; i != card; ++i) {
        uint32_t key = r[i];
        out[k] = key + base;
        k += bitmap_contains(bitmap, key);
    }
    return k;
}

size_t ss_intersect_chunk3(uint8_t const* l, uint8_t const* r, int blocks_l,
                           int blocks_r, uint32_t base, uint32_t* out) {
    assert(blocks_l >= 1 and blocks_l <= 256);
    assert(blocks_r >= 1 and blocks_r <= 256);
    uint8_t const* data_l = l + blocks_l * 2;
    uint8_t const* data_r = r + blocks_r * 2;
    uint32_t* tmp = out;

    int pl = 0;
    int pr = 0;
    while (true) {
        while (*l < *r) {
            if (++pl == blocks_l) {
                return size_t(tmp - out);
            }
            data_l += *(l + 1);
            l += 2;
        }
        while (*l > *r) {
            if (++pr == blocks_r) {
                return size_t(tmp - out);
            }
            data_r += *(r + 1);
            r += 2;
        }
        if (*l == *r) {
            uint8_t id = *l;
            ++l;
            ++r;
            int card_l = *l;
            int card_r = *r;
            int type_l = TYPE_BY_CARDINALITY(card_l);
            int type_r = TYPE_BY_CARDINALITY(card_r);

            uint32_t b = base + id * 256;
            uint32_t n = 0;

            switch (block_pair(type_l, type_r)) {
                case block_pair(type::sparse, type::sparse):
                    n = ss_intersect_block3(data_l, data_r, card_l, card_r, b,
                                            tmp);
                    break;
                case block_pair(type::sparse, type::dense):
                    n = ds_intersect_block3(data_r, data_l, card_l, b, tmp);
                    break;
                case block_pair(type::dense, type::sparse):
                    n = ds_intersect_block3(data_l, data_r, card_r, b, tmp);
                    break;
                case block_pair(type::dense, type::dense):
                    n = dd_intersect_block(data_l, data_r, b, tmp);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            tmp += n;

            if (++pl == blocks_l or ++pr == blocks_r) {
                return size_t(tmp - out);
            }

            data_l += card_l;
            data_r += card_r;
            ++l;
            ++r;
        }
    }

    return size_t(tmp - out);
}

size_t ds_intersect_chunk3(uint8_t const* l, uint8_t const* r, int blocks_r,
                           uint32_t base, uint32_t* out) {
    static uint64_t x[1024];
    std::fill(x, x + 1024, 0);
    uncompress_sparse_chunk3(r, blocks_r, x);
    return dd_intersect_chunk(l, reinterpret_cast<uint8_t const*>(x), base,
                              out);
}

size_t fs_intersect_chunk3(uint8_t const* l, uint8_t const* r, int blocks_r,
                           uint32_t base, uint32_t* out) {
    (void)l;
    return decode_sparse_chunk3(r, blocks_r, base, out);
}

size_t pairwise_intersection3(s_sequence const& l, s_sequence const& r,
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
            int blocks_l = 0;
            int blocks_r = 0;

            uint16_t type_l = it_l.type();
            uint16_t type_r = it_r.type();

            switch (chunk_pair(type_l, type_r)) {
                case chunk_pair(type::sparse, type::sparse):
                    blocks_l = it_l.blocks();
                    blocks_r = it_r.blocks();
                    if (blocks_l < blocks_r) {
                        n = ss_intersect_chunk3(it_l.data, it_r.data, blocks_l,
                                                blocks_r, base, out);
                    } else {
                        n = ss_intersect_chunk3(it_r.data, it_l.data, blocks_r,
                                                blocks_l, base, out);
                    }
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = ds_intersect_chunk3(it_r.data, it_l.data, it_l.blocks(),
                                            base, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = fs_intersect_chunk3(it_r.data, it_l.data, it_l.blocks(),
                                            base, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = ds_intersect_chunk3(it_l.data, it_r.data, it_r.blocks(),
                                            base, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = dd_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = fd_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = fs_intersect_chunk3(it_l.data, it_r.data, it_r.blocks(),
                                            base, out);
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