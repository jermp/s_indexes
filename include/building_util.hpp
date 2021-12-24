#pragma once

#include <cassert>

#include "constants.hpp"
#include "util.hpp"

namespace sliced {

struct slice {
    uint32_t left;
    uint32_t right;
};

template <typename W>
void set_bit(size_t position, std::vector<W>& bits) {
    assert(position < bits.size() * sizeof(W) * 8);
    size_t w = position / (sizeof(W) * 8);
    size_t o = position % (sizeof(W) * 8);
    bits[w] |= W(1) << o;
}

template <typename T>
void write_uint(T val, std::vector<uint8_t>& out) {
    auto ptr = reinterpret_cast<uint8_t const*>(&val);
    out.insert(out.end(), ptr, ptr + sizeof(T));
}

template <typename T = uint32_t>
void write_uint(T x, std::ofstream& out) {
    out.write(reinterpret_cast<char const*>(&x), sizeof(T));
}

void write_bits(uint32_t const* begin, size_t n, size_t bits, uint32_t base,
                std::vector<uint8_t>& out) {
    assert(bits % 64 == 0);
    std::vector<uint64_t> bitmap(bits / 64, 0);
    for (uint32_t i = 0; i != n; ++i, ++begin) {
        uint32_t val = *begin - base;
        set_bit(val, bitmap);
    }
    auto ptr = reinterpret_cast<uint8_t const*>(bitmap.data());
    out.insert(out.end(), ptr, ptr + bitmap.size() * sizeof(bitmap.front()));
}

uint32_t chunk_cardinality(uint32_t const* begin, uint32_t const* end,
                           slice s) {
    uint32_t c = 0;
    uint32_t prev = -1;
    while (begin != end and *begin < s.right) {
        assert(*begin >= s.left);
        assert(*begin - s.left < constants::chunk_size);
        if (*begin == prev) throw std::runtime_error("duplicate element");
        prev = *begin;
        ++begin;
        ++c;
    }
    assert(c > 0 and c <= constants::chunk_size);
    return c;
}

void block_bitsize(size_t block_size, statistics& stats) {
    stats.blocks += 1;
    assert(block_size <= constants::block_size);
    if (block_size == 0) {
        stats.empty_blocks += 1;
    } else if (block_size >= constants::block_sparseness_threshold - 1) {
        stats.dense_blocks += 1;
        stats.dense_blocks_bits += constants::block_size;
        stats.integers_in_dense_blocks += block_size;
    } else {
        assert(block_size <= constants::block_sparseness_threshold - 2);
        stats.sparse_blocks += 1;
        stats.integers_in_sparse_blocks += block_size;
        stats.sparse_blocks_bits += 8 * (block_size + 1);
        stats.sparse_blocks_cardinalities[block_size] += 1;
    }
}

statistics sparse_chunk_bitsize(uint32_t const* begin, uint32_t const* end,
                                slice s) {
    statistics stats;
    uint32_t base = s.left;
    size_t block_size = 0;
    while (begin != end and *begin < s.right) {
        uint32_t val = *begin - base;
        if (val >= constants::block_size) {
            block_bitsize(block_size, stats);
            base += constants::block_size;
            block_size = 0;
        } else {
            assert(val < constants::block_size);
            ++block_size;
            assert(block_size <= constants::block_size);
            ++begin;
        }
    }
    block_bitsize(block_size, stats);
    return stats;
}

}  // namespace sliced