#pragma once

#include "constants.hpp"

namespace sliced {

inline void set_bit(uint32_t position, uint64_t* out) {
    size_t w = position / 64;
    size_t o = position & 63;
    out[w] |= uint64_t(1) << o;
}

uint32_t uncompress_sparse_block(uint8_t const* begin, uint64_t* out) {
    uint32_t cardinality = *begin++;
    for (uint32_t i = 0; i != cardinality; ++i) {
        set_bit(*begin++, out);
    }
    return cardinality;
}

uint32_t uncompress_dense_block(uint8_t const* begin, uint64_t* out) {
    auto ptr = reinterpret_cast<uint64_t const*>(begin);
    memcpy(out, ptr, constants::block_size / 8);
    uint32_t c = 0;
    for (size_t i = 0; i != constants::block_size_in_64bit_words; ++i) {
        c += __builtin_popcountll(out[i]);
    }
    return c;
}

// uint32_t uncompress_full_block(uint8_t const* begin, uint64_t* out) {
//     (void)begin;
//     for (uint32_t i = 0; i != constants::block_size_in_64bit_words; ++i) {
//         out[i] = -1;
//     }
//     return constants::block_size;
// }

uint32_t uncompress_sparse_chunk(uint8_t const* begin, uint64_t* out) {
    uint8_t const* data = begin + 64;
    uint64_t* tmp = out;
    uint32_t uncompressed = 0;
    for (uint32_t i = 0; i != 64; ++i) {
        uint8_t header_byte = begin[i];
        if (header_byte == 0) {
            tmp += constants::block_size_in_64bit_words * 4;
        } else {
            for (uint32_t i = 0; i != 4; ++i) {
                uint8_t header = header_byte & 3;
                uint32_t u = 0;
                switch (header) {
                    case type::empty:
                        break;
                    case type::sparse:
                        u = uncompress_sparse_block(data, tmp);
                        data += u + 1;
                        break;
                    case type::dense:
                        u = uncompress_dense_block(data, tmp);
                        data += 32;
                        break;
                    // case type::full:
                    //     u = uncompress_full_block(data, tmp);
                    //     break;
                    default:
                        assert(false);
                        __builtin_unreachable();
                }
                tmp += constants::block_size_in_64bit_words;
                uncompressed += u;
                header_byte >>= 2;
            }
        }
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
                u = uncompress_sparse_chunk(it.data, out);
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