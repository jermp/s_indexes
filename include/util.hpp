#pragma once

#include <cstring>

namespace sliced {

size_t bytes_for(size_t bits) {
    return (bits + 8 - 1) / 8;
}

enum type { empty = 0, sparse = 1, dense = 2, full = 3 };

struct parameters {
    std::string collection_filename;
    double density;
};

struct statistics {
    statistics() {
        memset(this, 0, 24 * sizeof(uint64_t));
    }

    uint64_t sequences;

    uint64_t integers;
    uint64_t integers_in_sparse_chunks;
    uint64_t integers_in_dense_chunks;
    uint64_t integers_in_full_chunks;
    uint64_t integers_in_sparse_blocks;
    uint64_t integers_in_dense_blocks;
    uint64_t integers_in_full_blocks;

    uint64_t chunks;
    uint64_t empty_chunks;
    uint64_t sparse_chunks;
    uint64_t dense_chunks;
    uint64_t full_chunks;

    uint64_t blocks;
    uint64_t empty_blocks;
    uint64_t sparse_blocks;
    uint64_t dense_blocks;
    uint64_t full_blocks;

    uint64_t bits;
    uint64_t chunks_header_bits;
    uint64_t blocks_header_bits;
    uint64_t dense_chunks_bits;
    uint64_t dense_blocks_bits;
    uint64_t sparse_blocks_bits;
};

}  // namespace sliced