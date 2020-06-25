#pragma once

#include "next_geq.hpp"

namespace sliced {

struct next_geq_enumerator {
    next_geq_enumerator() {}

    next_geq_enumerator(s_sequence const& s)
        : m_chunk_id(-1)
        , m_id(0)
        , m_begin(nullptr)
        , m_end(nullptr)
        , m_data(nullptr)
        , m_size(s.size())
        , m_it(s.begin()) {}

    uint64_t size() const {
        return m_size;
    }

    uint32_t next_geq(uint32_t value) {
        uint32_t chunk_id = value >> 16;
        m_it.skip_to_value(chunk_id);

        if (m_it.base() >= value) {  // saturate
            CHUNK_MIN(m_it)
        }

        if (m_it.has_next()) {
            value &= 0xFFFF;
            switch (m_it.type()) {
                case type::sparse: {
                    uint32_t block_id = value >> 8;
                    if (m_chunk_id != m_it.id()) {
                        uint32_t blocks = m_it.blocks();
                        assert(blocks >= 1 and blocks <= 256);
                        m_begin = m_it.data;
                        m_data = m_begin + blocks * 2;
                        m_end = m_data;
                        m_id = *m_begin;
                        m_chunk_id = m_it.id();
                    }

                    while (m_id < block_id and m_begin != m_end) {
                        int c = *(m_begin + 1) + 1;
                        m_data += BYTES_BY_CARDINALITY(c);
                        m_begin += 2;
                        m_id = *m_begin;
                    }

                    if (m_begin != m_end) {
                        uint32_t base = m_id * 256;
                        if (base >= value) {  // saturate
                            BLOCK_MIN_
                            break;
                        }

                        value &= 0xFF;
                        if (value >
                            max_value_in_block(m_begin, m_data)) {  // saturate
                            if (m_begin + 2 == m_end) {
                                value = constants::not_found;
                                break;
                            }
                            int c = *(m_begin + 1) + 1;
                            m_data += BYTES_BY_CARDINALITY(c);
                            m_begin += 2;
                            m_id = *m_begin;
                            base = m_id * 256;
                            BLOCK_MIN_
                            break;
                        }
                        base = m_id * 256;
                        int c = *(m_begin + 1) + 1;
                        if (LIKELY(c < 31)) {  // block type is sparse
                            value =
                                next_geq_sparse_block(m_data, c, value) + base;
                        } else {
                            value = next_geq_bitmap(
                                        m_data,
                                        constants::block_size_in_64bit_words,
                                        value) +
                                    base;
                        }
                    } else {
                        value = constants::not_found;
                    }
                } break;
                case type::dense:
                    value = next_geq_bitmap(
                        m_it.data, constants::chunk_size_in_64bit_words, value);
                    break;
                case type::full:
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            if (value != constants::not_found) {
                return value + m_it.base();
            }

            // saturate
            m_it.next();
            if (m_it.has_next()) {
                CHUNK_MIN(m_it)
            }
        }

        return constants::not_found;
    }

private:
    uint32_t m_chunk_id;
    uint8_t m_id;
    uint8_t const* m_begin;
    uint8_t const* m_end;
    uint8_t const* m_data;
    uint64_t m_size;
    s_sequence::iterator m_it;
};

}  // namespace sliced