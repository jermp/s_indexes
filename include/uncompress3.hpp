#pragma once

#include "constants.hpp"
#include "uncompress.hpp"

namespace sliced {

uint32_t uncompress_sparse_block3(uint8_t const* begin, int cardinality,
                                  uint64_t* out) {
    for (int i = 0; i != cardinality; ++i) {
        set_bit(*begin++, out);
    }
    return cardinality;
}

uint32_t uncompress_sparse_chunk3(uint8_t const* begin, int blocks,
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
            u = uncompress_sparse_block3(data, card, tmp);
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

size_t s_sequence::uncompress3(uint64_t* out) {
    auto it = begin();
    size_t uncompressed = 0;
    uint16_t prev = 0;
    for (uint32_t i = 0; i != chunks; ++i) {
        uint16_t id = it.id();
        uint32_t u = 0;
        out += (id - prev) * constants::chunk_size_in_64bit_words;
        switch (it.type()) {
            case type::sparse:
                u = uncompress_sparse_chunk3(it.data, it.blocks(), out);
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