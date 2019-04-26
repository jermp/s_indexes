#pragma once

#include <cassert>

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
    while (*begin < s.right and begin != end) {
        assert(*begin >= s.left);
        assert(*begin - s.left < constants::chunk_size);
        ++begin;
        ++c;
    }
    return c;
}

}  // namespace sliced