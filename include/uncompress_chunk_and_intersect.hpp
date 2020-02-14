#pragma once

#include "uncompress.hpp"

namespace sliced {

// uint32_t uncompress_sparse_block_and_intersect(uint8_t const* begin,
//                                                int cardinality, uint64_t*
//                                                out) {
//     static std::vector<uint64_t> tmp(constants::block_size_in_64bit_words);
//     tmp[0] = 0;
//     tmp[1] = 0;
//     tmp[2] = 0;
//     tmp[3] = 0;
//     uncompress_sparse_block(begin, cardinality, tmp.data());
//     uint32_t c = 0;
//     for (size_t i = 0; i != constants::block_size_in_64bit_words; ++i) {
//         out[i] &= tmp[i];
//         c += __builtin_popcountll(out[i]);
//     }
//     return c;
// }

// uint32_t uncompress_dense_block_and_intersect(uint8_t const* begin,
//                                               uint64_t* out) {
//     uint64_t const* in = reinterpret_cast<uint64_t const*>(begin);
//     uint32_t c = 0;
//     for (size_t i = 0; i != constants::block_size_in_64bit_words; ++i) {
//         out[i] &= in[i];
//         c += __builtin_popcountll(out[i]);
//     }
//     return c;
// }

uint32_t uncompress_sparse_chunk_and_intersect(uint8_t const* begin, int blocks,
                                               uint64_t* out) {
    static std::vector<uint64_t> tmp(constants::chunk_size_in_64bit_words);
    std::fill(tmp.begin(), tmp.end(), 0);
    uncompress_sparse_chunk(begin, blocks, tmp.data());
    uint32_t c = 0;
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        out[i] &= tmp[i];
        c += __builtin_popcountll(out[i]);
    }
    return c;

    // assert(blocks >= 1 and blocks <= 256);
    // uint8_t const* data = begin + blocks * 2;
    // uint64_t* tmp = out;

    // uint8_t prev = 0;
    // uint32_t uncompressed = 0;
    // for (int i = 0; i != blocks; ++i) {
    //     uint8_t id = *begin;
    //     ++begin;
    //     int c = *begin + 1;
    //     int bytes = 32;
    //     int type = type::dense;
    //     if (LIKELY(c < 31)) {
    //         bytes = c;
    //         type = type::sparse;
    //     }

    //     // zero out any blocks in the middle
    //     for (uint64_t k = constants::block_size_in_64bit_words;
    //          k < (id - prev) * constants::block_size_in_64bit_words; ++k) {
    //         tmp[k] = 0;
    //     }

    //     tmp += (id - prev) * constants::block_size_in_64bit_words;
    //     uint32_t u = 0;
    //     if (type == type::sparse) {
    //         u = uncompress_sparse_block_and_intersect(data, c, tmp);
    //     } else if (type == type::dense) {
    //         u = uncompress_dense_block_and_intersect(data, tmp);
    //     }
    //     uncompressed += u;
    //     data += bytes;
    //     ++begin;
    //     prev = id;
    // }

    // // zero out any trailing blocks
    // tmp += constants::block_size_in_64bit_words;
    // for (uint64_t k = 0;
    //      k != (255 - prev) * constants::block_size_in_64bit_words; ++k) {
    //     tmp[k] = 0;
    // }

    // return uncompressed;
}

uint32_t uncompress_dense_chunk_and_intersect(uint8_t const* begin,
                                              uint64_t* out) {
    uint64_t const* in = reinterpret_cast<uint64_t const*>(begin);
    uint32_t c = 0;
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        out[i] &= in[i];
        c += __builtin_popcountll(out[i]);
    }
    return c;
}

inline size_t uncompress_chunk_and_intersect(s_sequence::iterator const& it,
                                             uint64_t* out,
                                             uint64_t cardinality) {
    switch (it.type()) {
        case type::sparse:
            return uncompress_sparse_chunk_and_intersect(it.data, it.blocks(),
                                                         out);
        case type::dense:
            return uncompress_dense_chunk_and_intersect(it.data, out);
        case type::full:
            return cardinality;
        default:
            assert(false);
            __builtin_unreachable();
    }
}

}  // namespace sliced