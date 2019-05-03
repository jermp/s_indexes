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
        int card = *begin;
        int type = TYPE_BY_CARDINALITY(card);
        uint32_t u = 0;
        tmp += (id - prev) * constants::block_size_in_64bit_words;
        if (type == type::sparse) {
            u = uncompress_sparse_block(data, card, tmp);
        } else if (type == type::dense) {
            u = uncompress_dense_block(data, tmp);
        }
        uncompressed += u;
        data += card;
        ++begin;
        prev = id;
    }

    return uncompressed;
}

uint32_t uncompress_dense_chunk(uint8_t const* begin, uint64_t* out) {
    auto ptr = reinterpret_cast<uint64_t const*>(begin);
    memcpy(out, ptr, constants::chunk_size / 8);
    uint32_t c = 0;
    for (size_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        c += __builtin_popcountll(out[i]);
    }
    return c;
}

uint32_t uncompress_full_chunk(uint8_t const* begin, uint64_t* out) {
    (void)begin;
    for (uint32_t i = 0; i != constants::chunk_size_in_64bit_words; ++i) {
        out[i] = -1;
    }
    return constants::chunk_size;
}

size_t s_sequence::uncompress(uint64_t* out) {
    auto it = begin();
    size_t uncompressed = 0;
    uint16_t prev = 0;
    for (uint32_t i = 0; i != chunks; ++i) {
        uint16_t id = it.id();
        uint32_t u = 0;
        out += (id - prev) * constants::chunk_size_in_64bit_words;
        switch (it.type()) {
            case type::sparse:
                u = uncompress_sparse_chunk(it.data, it.blocks(), out);
                break;
            case type::dense:
                u = uncompress_dense_chunk(it.data, out);
                break;
            case type::full:
                u = uncompress_full_chunk(it.data, out);
                break;
            default:
                assert(false);
                __builtin_unreachable();
        }
        uncompressed += u;
        prev = id;
        it.next();
    }
    assert(uncompressed > 0);
    return uncompressed;
}

}  // namespace sliced