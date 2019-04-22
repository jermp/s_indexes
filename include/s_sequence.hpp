#pragma once

#include "algorithms.hpp"

namespace sliced {

struct s_sequence {
    s_sequence(uint8_t const* begin) : m_begin(begin) {}

    size_t decode(uint32_t* out) {
        uint16_t const* header = reinterpret_cast<uint16_t const*>(m_begin);
        uint32_t num_chunks = *header++;
        // std::cout << "num_chunks " << num_chunks << std::endl;
        uint8_t const* data =
            m_begin + sizeof(uint16_t) + num_chunks * 3 * sizeof(uint16_t);
        size_t decoded = 0;

        for (uint32_t i = 0; i != num_chunks; ++i) {
            uint16_t chunk_id = *header;
            uint16_t chunk_type = *(header + 1);
            uint16_t offset = *(header + 2);

            // std::cout << "chunk_id " << chunk_id << std::endl;
            // std::cout << "chunk_type " << chunk_type << std::endl;
            // std::cout << "offset " << offset << std::endl;

            uint32_t d = 0;
            switch (chunk_type) {
                case type::sparse:
                    d = decode_sparse_chunk(data, out);
                    break;
                case type::dense:
                    d = decode_dense_chunk(data, out);
                    break;
                case type::full:
                    d = decode_full_chunk(data, out);
                    break;
                default:
                    assert(false);
            }

            uint32_t base = chunk_id << 16;
            for (size_t i = 0; i != d; ++i) {
                out[i] += base;
            }

            out += d;
            decoded += d;
            data += offset;
            header += 3;
        }

        assert(decoded > 0);
        return decoded;
    }

private:
    uint8_t const* m_begin;
};

}  // namespace sliced