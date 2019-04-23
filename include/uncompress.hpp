#pragma once

#include "configuration.hpp"

namespace sliced {

inline void set_bit(uint8_t position, uint64_t* out) {
    size_t w = position / 64;
    size_t o = position & 63;
    out[w] |= uint64_t(1) << o;
}

uint32_t uncompress_sparse_block(uint8_t const* begin, uint64_t* out) {
    uint32_t cardinality = *begin++;

    for (uint32_t i = 0; i < cardinality; ++i) {
        set_bit(*begin++, out);
    }

    // NOTE: need to reset words to 0
    // set_bit(*(begin + 0), out);
    // set_bit(*(begin + 1), out);
    // set_bit(*(begin + 2), out);
    // set_bit(*(begin + 3), out);
    // set_bit(*(begin + 4), out);
    // set_bit(*(begin + 5), out);
    // set_bit(*(begin + 6), out);
    // set_bit(*(begin + 7), out);

    // if (cardinality <= 8) {  // most likely
    //     return cardinality;
    // }

    // begin += 8;
    // for (uint32_t i = 8; i < cardinality; ++i) {
    //     set_bit(*begin++, out);
    // }

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

uint32_t uncompress_full_block(uint8_t const* begin, uint64_t* out) {
    (void)begin;
    for (uint32_t i = 0; i != constants::block_size_in_64bit_words; ++i) {
        out[i] = uint64_t(-1);
    }
    return constants::block_size;
}

uint32_t uncompress_sparse_chunk(uint8_t const* begin, uint64_t* out) {
    uint8_t const* data = begin + 64;
    uint64_t* tmp = out;
    uint32_t base = 0;
    uint32_t uncompressed = 0;
    for (uint32_t i = 0; i != 64; ++i) {
        uint8_t header_byte = begin[i];
        if (header_byte == 0) {
            base += 256 * 4;
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
                    case type::full:
                        u = uncompress_full_block(data, tmp);
                        break;
                }

                tmp += constants::block_size_in_64bit_words;
                base += 256;
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
        out[i] = uint64_t(-1);
    }
    return constants::chunk_size;
}

size_t s_sequence::uncompress(uint64_t* out) {
    uint16_t const* header = reinterpret_cast<uint16_t const*>(m_begin);
    uint32_t num_chunks = *header++;
    uint8_t const* data =
        m_begin + sizeof(uint16_t) + num_chunks * 3 * sizeof(uint16_t);
    size_t uncompressed = 0;

    uint16_t prev_chunk_id = 0;
    for (uint32_t i = 0; i != num_chunks; ++i) {
        uint16_t chunk_id = *header;
        uint16_t chunk_type = *(header + 1);
        uint16_t offset = *(header + 2);
        uint32_t u = 0;
        out +=
            (chunk_id - prev_chunk_id) * constants::chunk_size_in_64bit_words;

        switch (chunk_type) {
            case type::sparse:
                u = uncompress_sparse_chunk(data, out);
                break;
            case type::dense:
                u = uncompress_dense_chunk(data, out);
                break;
            case type::full:
                u = uncompress_full_chunk(data, out);
                break;
            default:
                assert(false);
        }

        uncompressed += u;
        data += offset;
        header += 3;
        prev_chunk_id = chunk_id;
    }

    assert(uncompressed > 0);
    return uncompressed;
}
}  // namespace sliced