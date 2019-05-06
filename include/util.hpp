#pragma once

#include <cstring>
#include "constants.hpp"

namespace sliced {

#define chunk_pair(l, r) (3 * (l) + (r))
#define block_pair(l, r) (2 * (l) + (r))

#define LIKELY(x) __builtin_expect(!!(x), 1)

#define OPERATE_BITMAPS(OP, l, r, size_in_64bit_words, base, out)    \
    uint64_t const* bitmap_l = reinterpret_cast<uint64_t const*>(l); \
    uint64_t const* bitmap_r = reinterpret_cast<uint64_t const*>(r); \
    size_t size = 0;                                                 \
    for (size_t i = 0; i != size_in_64bit_words; ++i) {              \
        uint64_t w = bitmap_l[i] OP bitmap_r[i];                     \
        while (w != 0) {                                             \
            uint64_t t = w & (~w + 1);                               \
            int r = __builtin_ctzll(w);                              \
            out[size++] = r + base;                                  \
            w ^= t;                                                  \
        }                                                            \
        base += 64;                                                  \
    }                                                                \
    return size;

size_t and_bitmaps(uint8_t const* l, uint8_t const* r,
                   size_t size_in_64bit_words, uint32_t base, uint32_t* out){
    OPERATE_BITMAPS(&, l, r, size_in_64bit_words, base, out)}

size_t or_bitmaps(uint8_t const* l, uint8_t const* r,
                  size_t size_in_64bit_words, uint32_t base, uint32_t* out) {
    OPERATE_BITMAPS(|, l, r, size_in_64bit_words, base, out)
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

size_t bytes_for(size_t bits) {
    return (bits + 8 - 1) / 8;
}

uint32_t chunks(uint64_t universe) {
    return universe
               ? (universe + constants::chunk_size - 1) / constants::chunk_size
               : 1;
}

enum type { empty = 0, sparse = 1, dense = 3, full = 2 };

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
        memset(this, 0, sizeof(*this));
    }

    uint64_t sequences;

    uint64_t integers;
    uint64_t integers_in_sparse_chunks;
    uint64_t integers_in_dense_chunks;
    uint64_t integers_in_full_chunks;
    uint64_t integers_in_sparse_blocks;
    uint64_t integers_in_dense_blocks;

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

    uint64_t bits;
    uint64_t chunks_header_bits;
    uint64_t blocks_header_bits;
    uint64_t dense_chunks_bits;
    uint64_t dense_blocks_bits;
    uint64_t sparse_blocks_bits;

    void accumulate(statistics const& other) {
        dense_blocks += other.dense_blocks;
        sparse_blocks += other.sparse_blocks;
        empty_blocks += other.empty_blocks;
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

        std::cout << "blocks: " << blocks << std::endl;
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