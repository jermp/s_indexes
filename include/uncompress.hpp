#pragma once

#include "constants.hpp"

namespace sliced {

uint32_t uncompress_sparse_block(uint8_t const* begin, int cardinality,
                                 uint64_t* out) {
    // for (int i = 0; i != cardinality; ++i) {
    //     set_bit(*begin++, out);
    // }
    // return cardinality;

    uint64_t offset, load, pos;
    const uint64_t shift = 6;
    uint8_t const* end = begin + cardinality;
    __asm volatile(
        "1:\n"
        "movzbq (%[begin]), %[pos]\n"
        "shrx %[shift], %[pos], %[offset]\n"
        "mov (%[out],%[offset],8), %[load]\n"
        "bts %[pos], %[load]\n"
        "mov %[load], (%[out],%[offset],8)\n"
        "add $1, %[begin]\n"
        "cmp %[begin], %[end]\n"
        "jnz 1b"
        : [ begin ] "+&r"(begin), [ load ] "=&r"(load), [ pos ] "=&r"(pos),
          [ offset ] "=&r"(offset)
        : [ end ] "r"(end), [ out ] "r"(out), [ shift ] "r"(shift));
    return cardinality;
}

uint32_t uncompress_dense_block(uint8_t const* begin, uint64_t* out) {
    memcpy(out, reinterpret_cast<uint64_t const*>(begin),
           constants::block_size / 8);
    uint32_t c = 0;
    for (size_t i = 0; i != constants::block_size_in_64bit_words; ++i) {
        c += __builtin_popcountll(out[i]);
    }
    return c;
}

uint32_t uncompress_sparse_chunk(uint8_t const* begin, int blocks,
                                 uint64_t* out) {
    assert(blocks >= 1 and blocks <= 256);
    uint8_t const* data = begin + blocks * 2;
    uint64_t* tmp = out;

    uint8_t prev = 0;
    uint32_t uncompressed = 0;
    for (int i = 0; i != blocks; ++i) {
        uint8_t id = *begin;
        ++begin;
        int c = *begin + 1;
        int bytes = 32;
        int type = type::dense;
        if (LIKELY(c < 31)) {
            bytes = c;
            type = type::sparse;
        }
        uint32_t u = 0;
        tmp += (id - prev) * constants::block_size_in_64bit_words;
        if (type == type::sparse) {
            u = uncompress_sparse_block(data, c, tmp);
        } else if (type == type::dense) {
            u = uncompress_dense_block(data, tmp);
        }
        uncompressed += u;
        data += bytes;
        ++begin;
        prev = id;
    }

    return uncompressed;
}

uint32_t uncompress_dense_chunk(uint8_t const* begin, uint64_t* out) {
    memcpy(out, begin, constants::chunk_size / 8);
    uint32_t c = 0;
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        c += __builtin_popcountll(out[i]);
    }
    return c;
}

inline uint32_t uncompress_full_chunk(uint64_t* out) {
    for (uint32_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        out[i] = uint64_t(-1);
    }
    return constants::chunk_size;
}

inline size_t uncompress_chunk(s_sequence::iterator const& it, uint64_t* out) {
    switch (it.type()) {
        case type::sparse: {
            for (uint64_t i = 0; i != 1024; ++i) out[i] = 0;
            return uncompress_sparse_chunk(it.data, it.blocks(), out);
        }
        case type::dense:
            return uncompress_dense_chunk(it.data, out);
        case type::full:
            return uncompress_full_chunk(out);
        default:
            assert(false);
            __builtin_unreachable();
    }
}

size_t s_sequence::uncompress(uint64_t* out) const {
    auto it = begin();
    size_t uncompressed = 0;
    uint16_t prev = 0;
    for (uint32_t i = 0; i != chunks; ++i) {
        uint16_t id = it.id();
        out += (id - prev) * constants::chunk_size_in_64bit_words;
        uncompressed += uncompress_chunk(it, out);
        prev = id;
        it.next();
    }
    assert(uncompressed > 0);
    return uncompressed;
}

}  // namespace sliced