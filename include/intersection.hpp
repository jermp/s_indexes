#pragma once

#include "configuration.hpp"
#include "decode.hpp"
#include "uncompress.hpp"

#define chunk_pair(l, r) (3 * (l) + (r))
#define block_pair(l, r) (4 * (l) + (r))

namespace sliced {

size_t ss_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    // NOTE: this slows down the code,
    // although it is usually the most frequent case
    // if (*l == 1 and *r == 1) {
    //     ++l;
    //     ++r;
    //     if (*l == *r) {
    //         *out = *l;
    //         return 1;
    //     }
    //     return 0;
    // }

    uint8_t const* end_l = l + *l + 1;
    uint8_t const* end_r = r + *r + 1;
    ++l;
    ++r;
    size_t size = 0;

    // do {  // avoid testing condition for most-frequent case
    //     if (*l == *r) {
    //         out[size++] = *l;
    //         ++l;
    //         ++r;
    //     } else if (*l < *r) {
    //         ++l;
    //     } else {
    //         ++r;
    //     }
    // } while (l < end_l and r < end_r);

    // NOTE: faster than the approach above
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
            out[size++] = *l;
            if (++l == end_l or ++r == end_r) {
                return size;
            }
        }
    }

    return size;
}

size_t intersect_bitmap(uint8_t const* l, uint8_t const* r,
                        size_t size_in_64bit_words, uint32_t* out) {
    uint64_t const* bitmap_l = reinterpret_cast<uint64_t const*>(l);
    uint64_t const* bitmap_r = reinterpret_cast<uint64_t const*>(r);
    size_t pos = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap_l[i] & bitmap_r[i];
        while (w != 0) {
            uint64_t t = w & -w;
            int r = __builtin_ctzll(w);
            out[pos++] = i * 64 + r;
            w ^= t;
        }
    }
    return pos;
}

size_t dd_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    return intersect_bitmap(l, r, constants::block_size_in_64bit_words, out);
}

inline bool bitmap_contains(uint64_t const* bitmap, uint32_t pos) {
    uint64_t word = bitmap[pos >> 6];
    word >>= pos & 63;
    return word & 1;
}

size_t ds_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(l);
    uint32_t cardinality = *r++;
    uint32_t k = 0;
    for (uint32_t i = 0; i != cardinality; ++i) {
        uint32_t key = r[i];
        out[k] = key;
        k += bitmap_contains(bitmap, key);
    }
    return k;
}

size_t fs_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_sparse_block(r, out);
}

size_t fd_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_dense_block(r, out);
}

size_t ff_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)r;
    return decode_full_block(l, out);
}

size_t ss_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    uint8_t const* data_l = l + 64;
    uint8_t const* data_r = r + 64;
    uint32_t* tmp = out;
    uint32_t base = 0;
    uint32_t size = 0;

    for (uint32_t i = 0; i != 64; ++i) {
        uint8_t header_byte_l = l[i];
        uint8_t header_byte_r = r[i];

        if (header_byte_l == 0 and header_byte_r == 0) {
            base += 256 * 4;
        } else {
            for (uint32_t i = 0; i != 4; ++i) {
                uint8_t header_l = header_byte_l & 3;
                uint8_t header_r = header_byte_r & 3;
                uint32_t n = 0;

                if (header_l == 0) {
                    switch (header_r) {
                        case type::empty:
                            break;
                        case type::sparse:
                            data_r += *data_r + 1;
                            break;
                        case type::dense:
                            data_r += 32;
                            break;
                        case type::full:
                            break;
                    }
                } else if (header_r == 0) {
                    switch (header_l) {
                        case type::sparse:
                            data_l += *data_l + 1;
                            break;
                        case type::dense:
                            data_l += 32;
                            break;
                        case type::full:
                            break;
                    }

                } else {
                    switch (block_pair(header_l, header_r)) {
                        case block_pair(type::sparse, type::sparse):
                            // std::cout << "0\n";
                            n = ss_intersect_block(data_l, data_r, tmp);
                            data_l += *data_l + 1;
                            data_r += *data_r + 1;
                            break;
                        case block_pair(type::sparse, type::dense):
                            // std::cout << "1\n";
                            n = ds_intersect_block(data_r, data_l, tmp);
                            data_r += 32;
                            data_l += *data_l + 1;
                            break;
                        case block_pair(type::dense, type::sparse):
                            // std::cout << "2\n";
                            n = ds_intersect_block(data_l, data_r, tmp);
                            data_l += 32;
                            data_r += *data_r + 1;
                            break;
                        case block_pair(type::dense, type::dense):
                            // std::cout << "3\n";
                            n = dd_intersect_block(data_l, data_r, tmp);
                            data_l += 32;
                            data_r += 32;
                            break;
                        case block_pair(type::sparse, type::full):
                            // std::cout << "4\n";
                            n = fs_intersect_block(data_r, data_l, tmp);
                            data_l += n + 1;
                            break;
                        case block_pair(type::full, type::sparse):
                            // std::cout << "5\n";
                            n = fs_intersect_block(data_l, data_r, tmp);
                            data_r += n + 1;
                            break;
                        case block_pair(type::dense, type::full):
                            // std::cout << "6\n";
                            n = fd_intersect_block(data_r, data_l, tmp);
                            data_l += 32;
                            break;
                        case block_pair(type::full, type::dense):
                            // std::cout << "7\n";
                            n = fd_intersect_block(data_l, data_r, tmp);
                            data_r += 32;
                            break;
                        case block_pair(type::full, type::full):
                            // std::cout << "8\n";
                            n = ff_intersect_block(data_r, data_l, tmp);
                            break;
                        default:
                            assert(false);
                            __builtin_unreachable();
                    }
                }

                // NOTE1: this is a bit costly
                // NOTE2: this is as fast as SIMD version below
                // NOTE3: fixed-length loop is much slower because most
                // values of n are small

                // NOTE4: can try to pass base to the
                // blocks' decoding functions (also for decoding)
                for (size_t i = 0; i != n; ++i) {
                    tmp[i] += base;
                }

                // __m256i base_vec = _mm256_set1_epi32(base);
                // size_t k = (n + 7) / 8 * 8;
                // for (size_t i = 0; i != k; i += 8) {
                //     __m256i in_vec =
                //         _mm256_load_si256((__m256i const*)(tmp + i));
                //     in_vec = _mm256_add_epi32(base_vec, in_vec);
                //     _mm256_storeu_si256((__m256i*)(tmp + i), in_vec);
                // }

                tmp += n;
                base += 256;
                size += n;
                header_byte_l >>= 2;
                header_byte_r >>= 2;
            }
        }
    }

    return size;
}

size_t dd_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    return intersect_bitmap(l, r, constants::chunk_size_in_64bit_words, out);
}

size_t ds_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    static uint64_t x[1024];
    std::fill(x, x + 1024, 0);
    uncompress_sparse_chunk(r, x);
    return dd_intersect_chunk(l, reinterpret_cast<uint8_t const*>(x), out);
}

size_t fs_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_sparse_chunk(r, out);
}

size_t fd_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)l;
    return decode_dense_chunk(r, out);
}

size_t ff_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    (void)r;
    return decode_full_chunk(l, out);
}

size_t pairwise_intersection(s_sequence const& l, s_sequence const& r,
                             uint32_t* out) {
    auto it_l = l.begin();
    auto it_r = r.begin();
    size_t size = 0;
    while (it_l.has_next() and it_r.has_next()) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):
                    n = ss_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = ds_intersect_chunk(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = fs_intersect_chunk(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = ds_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = dd_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = fd_intersect_chunk(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = fs_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::dense):
                    n = fd_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::full):
                    n = ff_intersect_chunk(it_l.data, it_r.data, out);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            // NOTE: this is not costly
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