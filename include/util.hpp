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

struct query {
    uint32_t i;
    uint32_t j;
};

struct statistics {
    statistics() {
        memset(this, 0, 26 * sizeof(uint64_t));
    }

    uint64_t sequences;

    uint64_t integers;
    uint64_t integers_in_sparse_chunks;
    uint64_t integers_in_very_sparse_chunks;
    uint64_t integers_in_dense_chunks;
    uint64_t integers_in_full_chunks;
    uint64_t integers_in_sparse_blocks;
    uint64_t integers_in_dense_blocks;
    uint64_t integers_in_full_blocks;

    uint64_t chunks;
    uint64_t empty_chunks;
    uint64_t sparse_chunks;
    uint64_t very_sparse_chunks;
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

    void accumulate(statistics const& other) {
        full_blocks += other.full_blocks;
        dense_blocks += other.dense_blocks;
        sparse_blocks += other.sparse_blocks;
        empty_blocks += other.empty_blocks;

        integers_in_full_blocks += other.integers_in_full_blocks;
        integers_in_dense_blocks += other.integers_in_dense_blocks;
        integers_in_sparse_blocks += other.integers_in_sparse_blocks;

        dense_blocks_bits += other.dense_blocks_bits;
        sparse_blocks_bits += other.sparse_blocks_bits;
    }

    void print() {
        std::cout << "processed " << sequences << " sequences, " << integers
                  << " integers" << std::endl;

        std::cout << "chunks: " << chunks << std::endl;
        std::cout << "full chunks: " << full_chunks << " ("
                  << integers_in_full_chunks * 100.0 / integers << "% of ints)"
                  << std::endl;
        std::cout << "empty chunks: " << empty_chunks << " ("
                  << empty_chunks * 100.0 / chunks << "% of chunks)"
                  << std::endl;
        std::cout << "dense chunks: " << dense_chunks << " ("
                  << integers_in_dense_chunks * 100.0 / integers << "% of ints)"
                  << std::endl;
        std::cout << "sparse chunks: " << sparse_chunks << " ("
                  << integers_in_sparse_chunks * 100.0 / integers
                  << "% of ints)" << std::endl;
        std::cout << "very sparse chunks: " << very_sparse_chunks << " ("
                  << integers_in_very_sparse_chunks * 100.0 / integers
                  << "% of ints)" << std::endl;

        std::cout << "blocks: " << blocks << std::endl;
        std::cout << "full blocks: " << full_blocks << " ("
                  << integers_in_full_blocks * 100.0 / integers << "% of ints)"
                  << std::endl;
        std::cout << "empty blocks: " << empty_blocks << " ("
                  << empty_blocks * 100.0 / blocks << "% of blocks)"
                  << std::endl;
        std::cout << "dense blocks: " << dense_blocks << " ("
                  << integers_in_dense_blocks * 100.0 / integers << "% of ints)"
                  << std::endl;
        std::cout << "sparse blocks: " << sparse_blocks << " ("
                  << integers_in_sparse_blocks * 100.0 / integers
                  << "% of ints)" << std::endl;

        std::cout << double(chunks_header_bits) / integers
                  << " [bpi] for chunks' headers" << std::endl;
        std::cout << double(blocks_header_bits) / integers
                  << " [bpi] for blocks' headers" << std::endl;
        std::cout << double(dense_chunks_bits) / integers
                  << " [bpi] for dense chunks" << std::endl;
        std::cout << double(dense_blocks_bits) / integers
                  << " [bpi] for dense blocks" << std::endl;
        std::cout << double(sparse_blocks_bits) / integers
                  << " [bpi] for sparse blocks" << std::endl;

        std::cout << "total bpi: " << double(bits) / integers << std::endl;
    }
};

}  // namespace sliced