#pragma once

#include "uncompress.hpp"

namespace sliced {

void uncompress_sparse_chunk_and_merge(uint8_t const* begin, int blocks,
                                       uint64_t* out) {
    static std::vector<uint64_t> tmp(constants::chunk_size_in_64bit_words);
    std::fill(tmp.begin(), tmp.end(), 0);
    uncompress_sparse_chunk(begin, blocks, tmp.data());
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        out[i] |= tmp[i];
    }
}

void uncompress_dense_chunk_and_merge(uint8_t const* begin, uint64_t* out) {
    uint64_t const* in = reinterpret_cast<uint64_t const*>(begin);
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        out[i] |= in[i];
    }
}

void uncompress_full_chunk_and_merge(uint64_t* out) {
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        out[i] = uint64_t(-1);
    }
}

inline void uncompress_chunk_and_merge(s_sequence::iterator const& it,
                                       uint64_t* out) {
    switch (it.type()) {
        case type::sparse: {
            uncompress_sparse_chunk_and_merge(it.data, it.blocks(), out);
            break;
        }
        case type::dense: {
            uncompress_dense_chunk_and_merge(it.data, out);
            break;
        }
        case type::full: {
            uncompress_full_chunk_and_merge(out);
            break;
        }
        default:
            assert(false);
            __builtin_unreachable();
    }
}

}  // namespace sliced