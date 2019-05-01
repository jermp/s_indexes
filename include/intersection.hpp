#pragma once

// #include "tables.hpp"
#include "constants.hpp"
#include "decode.hpp"
#include "uncompress.hpp"

#define chunk_pair(l, r) (3 * (l) + (r))
// #define block_pair(l, r) (4 * (l) + (r))
#define block_pair(l, r) (2 * (l) + (r))

namespace sliced {

// inline uint32_t search_key(uint8_t const* array, uint32_t key, uint32_t* out)
// {
//     uint32_t cardinality = *array++;
//     for (uint32_t i = 0; i != cardinality; ++i) {
//         if (array[i] > key) {
//             return 0;
//         } else if (array[i] == key) {
//             *out = key;
//             return 1;
//         }
//     }
//     return 0;
// }

size_t ss_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    // if (*l == 1) {
    //     ++l;
    //     return search_key(r, *l, out);
    // }

    // if (*r == 1) {
    //     ++r;
    //     return search_key(l, *r, out);
    // }

    assert(*l <= constants::block_sparseness_threshold - 1);
    assert(*r <= constants::block_sparseness_threshold - 1);
    uint8_t const* end_l = l + *l + 1;
    uint8_t const* end_r = r + *r + 1;
    size_t size = 0;
    ++l;
    ++r;

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

size_t intersect_bitmap(uint8_t const* l, uint8_t const* r,
                        size_t size_in_64bit_words, uint32_t base,
                        uint32_t* out) {
    uint64_t const* bitmap_l = reinterpret_cast<uint64_t const*>(l);
    uint64_t const* bitmap_r = reinterpret_cast<uint64_t const*>(r);
    size_t pos = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap_l[i] & bitmap_r[i];
        while (w != 0) {
            uint64_t t = w & (~w + 1);
            int r = __builtin_ctzll(w);
            out[pos++] = r + base;
            w ^= t;
        }
        base += 64;
    }
    return pos;
}

inline size_t dd_intersect_block(uint8_t const* l, uint8_t const* r,
                                 uint32_t base, uint32_t* out) {
    return intersect_bitmap(l, r, constants::block_size_in_64bit_words, base,
                            out);
}

inline bool bitmap_contains(uint64_t const* bitmap, uint64_t pos) {
    // uint64_t w = bitmap[pos >> 6];
    // w >>= pos & 63;
    // return w & 1;

    uint64_t r;
    uint64_t w = bitmap[pos >> 6];
    __asm volatile(
        "bt %2,%1\n"
        "sbb %0,%0"
        : "=r"(r)
        : "r"(w), "r"(pos));
    return r;
}

size_t ds_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(l);
    uint32_t cardinality = *r++;
    uint32_t k = 0;
    for (uint32_t i = 0; i != cardinality; ++i) {
        uint32_t key = r[i];
        out[k] = key + base;
        k += bitmap_contains(bitmap, key);
    }
    return k;
}

// size_t fs_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t base,
//                           uint32_t* out) {
//     (void)l;
//     return decode_sparse_block(r, base, out);
// }

// size_t fd_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t base,
//                           uint32_t* out) {
//     (void)l;
//     return decode_dense_block(r, base, out);
// }

// size_t ff_intersect_block(uint8_t const* l, uint8_t const* r, uint32_t base,
//                           uint32_t* out) {
//     (void)r;
//     return decode_full_block(l, base, out);
// }

// struct chunk_iterator {
//     chunk_iterator(uint8_t const* addr, uint32_t base)
//         : header(addr)
//         , data(addr + 64)
//         , position(0)
//         , base(base) {}

//     void advance(uint32_t n) {
//         assert(position < 256);
//         assert(n >= position);
//         uint32_t skip = n - position;
//         for (uint32_t i = 0; i != skip; ++i) {
//             switch (type()) {
//                 case type::empty:
//                     break;
//                 case type::sparse:
//                     data += *data + 1;
//                     break;
//                 case type::dense:
//                     data += 32;
//                     break;
//                 default:
//                     assert(false);
//                     __builtin_unreachable();
//             }
//             base += 256;
//             ++position;
//             if (position == 256) {
//                 return;
//             }
//         }

//         while (type() == type::empty) {
//             base += 256;
//             ++position;
//             if (position == 256) {
//                 return;
//             }
//         }
//     }

//     inline uint32_t type() {
//         return (header[position >> 2] >> (2 * (position & 3))) & 3;
//     }

//     uint8_t const* header;
//     uint8_t const* data;
//     uint32_t position;
//     uint32_t base;
// };

size_t ss_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    // uint32_t* tmp = out;
    // uint32_t size = 0;

    // chunk_iterator cit_l(l, base);
    // chunk_iterator cit_r(r, base);

    // uint32_t p = 0;
    // while (true) {
    //     cit_l.advance(p);
    //     if (cit_l.position == 256) {
    //         return size;
    //     }

    //     cit_r.advance(cit_l.position);
    //     assert(cit_r.position >= cit_l.position);
    //     if (cit_r.position == 256) {
    //         return size;
    //     }

    //     if (cit_l.position == cit_r.position) {
    //         uint32_t n = 0;
    //         assert(cit_l.base == cit_r.base);
    //         switch (block_pair(cit_l.type(), cit_r.type())) {
    //             case block_pair(type::sparse, type::sparse):
    //                 n = ss_intersect_block(cit_l.data, cit_r.data,
    //                 cit_l.base,
    //                                        tmp);
    //                 break;
    //             case block_pair(type::sparse, type::dense):
    //                 n = ds_intersect_block(cit_r.data, cit_l.data,
    //                 cit_l.base,
    //                                        tmp);
    //                 break;
    //             case block_pair(type::dense, type::sparse):
    //                 n = ds_intersect_block(cit_l.data, cit_r.data,
    //                 cit_l.base,
    //                                        tmp);
    //                 break;
    //             case block_pair(type::dense, type::dense):
    //                 n = dd_intersect_block(cit_l.data, cit_r.data,
    //                 cit_l.base,
    //                                        tmp);
    //                 break;
    //             default:
    //                 assert(false);
    //                 __builtin_unreachable();
    //         }
    //         tmp += n;
    //         size += n;
    //         p = cit_l.position + 1;
    //     } else {
    //         p = cit_r.position;
    //     }
    // }

    uint8_t const* data_l = l + 64;
    uint8_t const* data_r = r + 64;
    uint32_t* tmp = out;
    uint32_t size = 0;

    for (int i = 0; i != 64; ++i) {
        uint8_t header_byte_l = l[i];
        uint8_t header_byte_r = r[i];

        if (header_byte_l == 0 and header_byte_r == 0) {
            base += 256 * 4;
            // std::cout << "0\n";
            // } else if (header_byte_l == 0) {
            //     for (int i = 0; i != 4; ++i) {
            //         uint8_t header_r = header_byte_r & 3;
            //         if (header_r == type::sparse) {
            //             data_r += *data_r + 1;
            //         } else if (header_r == type::dense) {
            //             data_r += 32;
            //         }
            //         header_byte_r >>= 2;
            //     }
            //     base += 256 * 4;
            // } else if (header_byte_r == 0) {
            //     for (int i = 0; i != 4; ++i) {
            //         uint8_t header_l = header_byte_l & 3;
            //         if (header_l == type::sparse) {
            //             data_l += *data_l + 1;
            //         } else if (header_l == type::dense) {
            //             data_l += 32;
            //         }
            //         header_byte_l >>= 2;
            //     }
            //     base += 256 * 4;
        } else if ((header_byte_l & header_byte_r) == 0) {
            // std::cout << "1\n";
            for (int i = 0; i != 4; ++i) {
                uint8_t header_l = header_byte_l & 3;
                uint8_t header_r = header_byte_r & 3;
                if (header_l == type::sparse) {
                    data_l += *data_l + 1;
                } else if (header_l == type::dense) {
                    data_l += 32;
                }

                if (header_r == type::sparse) {
                    data_r += *data_r + 1;
                } else if (header_r == type::dense) {
                    data_r += 32;
                }

                header_byte_l >>= 2;
                header_byte_r >>= 2;
            }
            base += 256 * 4;
        } else {
            // std::cout << "2\n";
            for (int i = 0; i != 4; ++i) {
                // std::cout << "2\n";
                uint8_t header_l = header_byte_l & 3;
                uint8_t header_r = header_byte_r & 3;
                uint32_t n = 0;

                if (header_l == 0) {
                    if (header_r == type::sparse) {
                        data_r += *data_r + 1;
                    } else if (header_r == type::dense) {
                        data_r += 32;
                    }
                } else if (header_r == 0) {
                    if (header_l == type::sparse) {
                        data_l += *data_l + 1;
                    } else if (header_l == type::dense) {
                        data_l += 32;
                    }
                } else {
                    // std::cout << "2\n";
                    switch (block_pair(header_l, header_r)) {
                        case block_pair(type::sparse, type::sparse):
                            // std::cout << "0\n";
                            n = ss_intersect_block(data_l, data_r, base, tmp);
                            data_l += *data_l + 1;
                            data_r += *data_r + 1;
                            break;
                        case block_pair(type::sparse, type::dense):
                            // std::cout << "1\n";
                            n = ds_intersect_block(data_r, data_l, base, tmp);
                            data_r += 32;
                            data_l += *data_l + 1;
                            break;
                        case block_pair(type::dense, type::sparse):
                            // std::cout << "2\n";
                            n = ds_intersect_block(data_l, data_r, base, tmp);
                            data_l += 32;
                            data_r += *data_r + 1;
                            break;
                        case block_pair(type::dense, type::dense):
                            // std::cout << "3\n";
                            n = dd_intersect_block(data_l, data_r, base, tmp);
                            data_l += 32;
                            data_r += 32;
                            break;
                        // case block_pair(type::sparse, type::full):
                        //     // std::cout << "4\n";
                        //     n = fs_intersect_block(data_r, data_l, base,
                        //     tmp); data_l += n + 1; break;
                        // case block_pair(type::full, type::sparse):
                        //     // std::cout << "5\n";
                        //     n = fs_intersect_block(data_l, data_r, base,
                        //     tmp); data_r += n + 1; break;
                        // case block_pair(type::dense, type::full):
                        //     // std::cout << "6\n";
                        //     n = fd_intersect_block(data_r, data_l, base,
                        //     tmp); data_l += 32; break;
                        // case block_pair(type::full, type::dense):
                        //     // std::cout << "7\n";
                        //     n = fd_intersect_block(data_l, data_r, base,
                        //     tmp); data_r += 32; break;
                        // case block_pair(type::full, type::full):
                        //     // std::cout << "8\n";
                        //     n = ff_intersect_block(data_r, data_l, base,
                        //     tmp); break;
                        default:
                            assert(false);
                            __builtin_unreachable();
                    }
                }

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

// size_t ss_intersect_chunk1(uint8_t const* l, uint8_t const* r, uint32_t
// base,
//                            uint64_t* bitmap1, uint64_t* bitmap2,
//                            uint32_t* out) {
//     uncompress_sparse_chunk(l, bitmap1);
//     uncompress_sparse_chunk(r, bitmap2);
//     size_t size = 0;
//     for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
//         uint64_t w = bitmap1[i] & bitmap2[i];
//         while (w != 0) {
//             uint64_t t = w & -w;
//             int r = __builtin_ctzll(w);
//             out[size++] = i * 64 + r + base;
//             w ^= t;
//         }
//         bitmap1[i] = 0;
//         bitmap2[i] = 0;
//     }
//     return size;
// }

size_t dd_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    return intersect_bitmap(l, r, constants::chunk_size_in_64bit_words, base,
                            out);

    // __m256i base_vec = _mm256_set1_epi32(base);
    // __m256i inc_vec = _mm256_set1_epi32(64);
    // __m256i add8 = _mm256_set1_epi32(8);
    // uint64_t const* bitmap_l = reinterpret_cast<uint64_t const*>(l);
    // uint64_t const* bitmap_r = reinterpret_cast<uint64_t const*>(r);

    // size_t decoded = 0;
    // for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
    //     uint64_t w = bitmap_l[i] & bitmap_r[i];
    //     if (w == 0) {
    //         base_vec = _mm256_add_epi32(base_vec, inc_vec);
    //     } else {
    //         for (int k = 0; k < 4; ++k) {  // process 2 bytes of data at a
    //         time
    //             uint8_t byte1 = (uint8_t)w;
    //             uint8_t byte2 = (uint8_t)(w >> 8);
    //             w >>= 16;
    //             __m256i vec1 = _mm256_load_si256(
    //                 (const __m256i*)tables::dictionary[byte1]);
    //             __m256i vec2 = _mm256_load_si256(
    //                 (const __m256i*)tables::dictionary[byte2]);
    //             uint8_t advance1 = tables::size[byte1];
    //             uint8_t advance2 = tables::size[byte2];
    //             vec1 = _mm256_add_epi32(base_vec, vec1);
    //             base_vec = _mm256_add_epi32(base_vec, add8);
    //             vec2 = _mm256_add_epi32(base_vec, vec2);
    //             base_vec = _mm256_add_epi32(base_vec, add8);
    //             _mm256_storeu_si256((__m256i*)(out + decoded), vec1);
    //             decoded += advance1;
    //             _mm256_storeu_si256((__m256i*)(out + decoded), vec2);
    //             decoded += advance2;
    //         }
    //     }
    // }

    // return decoded;
}

size_t ds_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    static uint64_t x[1024];
    std::fill(x, x + 1024, 0);
    uncompress_sparse_chunk(r, x);
    return dd_intersect_chunk(l, reinterpret_cast<uint8_t const*>(x), base,
                              out);
}

size_t fs_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    (void)l;
    return decode_sparse_chunk(r, base, out);
}

size_t fd_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    (void)l;
    return decode_dense_chunk(r, base, out);
}

size_t ff_intersect_chunk(uint8_t const* l, uint8_t const* r, uint32_t base,
                          uint32_t* out) {
    (void)r;
    return decode_full_chunk(l, base, out);
}

// size_t pairwise_intersection1(s_sequence const& l, s_sequence const& r,
//                               uint64_t* bitmap1, uint64_t* bitmap2,
//                               uint32_t* out) {
//     auto it_l = l.begin();
//     auto it_r = r.begin();
//     size_t size = 0;
//     while (it_l.has_next() and it_r.has_next()) {
//         uint16_t id_l = it_l.id();
//         uint16_t id_r = it_r.id();

//         if (id_l == id_r) {
//             uint32_t n = 0;
//             uint32_t base = id_l << 16;
//             switch (chunk_pair(it_l.type(), it_r.type())) {
//                 case chunk_pair(type::sparse, type::sparse):
//                     n = ss_intersect_chunk1(it_l.data, it_r.data, base,
//                     bitmap1,
//                                             bitmap2, out);
//                     break;
//                 case chunk_pair(type::sparse, type::dense):
//                     // n = ds_intersect_chunk(it_r.data, it_l.data, base,
//                     // out);
//                     break;
//                 case chunk_pair(type::sparse, type::full):
//                     // n = fs_intersect_chunk(it_r.data, it_l.data, base,
//                     // out);
//                     break;
//                 case chunk_pair(type::dense, type::sparse):
//                     // n = ds_intersect_chunk(it_l.data, it_r.data, base,
//                     // out);
//                     break;
//                 case chunk_pair(type::dense, type::dense):
//                     n = dd_intersect_chunk(it_l.data, it_r.data, base,
//                     out); break;
//                 case chunk_pair(type::dense, type::full):
//                     n = fd_intersect_chunk(it_r.data, it_l.data, base,
//                     out); break;
//                 case chunk_pair(type::full, type::sparse):
//                     // n = fs_intersect_chunk(it_l.data, it_r.data, base,
//                     // out);
//                     break;
//                 case chunk_pair(type::full, type::dense):
//                     n = fd_intersect_chunk(it_l.data, it_r.data, base,
//                     out); break;
//                 case chunk_pair(type::full, type::full):
//                     n = ff_intersect_chunk(it_l.data, it_r.data, base,
//                     out); break;
//                 default:
//                     assert(false);
//                     __builtin_unreachable();
//             }

//             out += n;
//             size += n;
//             it_l.next();
//             it_r.next();

//         } else if (id_l < id_r) {
//             it_l.advance(id_r);
//         } else {
//             it_r.advance(id_l);
//         }
//     }
//     return size;
// }

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
            uint32_t base = id_l << 16;
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):
                    n = ss_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = ds_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = fs_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = ds_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = dd_intersect_chunk(it_l.data, it_r.data, base, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = fd_intersect_chunk(it_r.data, it_l.data, base, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = fs_intersect_chunk(it_l.data, it_r.data, base, out);
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