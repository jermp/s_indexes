#pragma once

#include "decode.hpp"

namespace sliced {

struct enumerator {
    enumerator() {
        m_buf.resize(constants::chunk_size);
    }

    void init(s_sequence const& s, uint32_t past_the_end) {
        m_it = s.begin();
        m_chunk = 0;
        m_chunks = s.chunks;
        m_i = 0;
        m_cardinality = m_it.cardinality();
        m_past_the_end = past_the_end;
        m_has_next = true;
        decode_chunk(m_it, m_buf.data());
    }

    void next() {
        if (++m_i == m_cardinality) {
            if (++m_chunk == m_chunks) {
                m_has_next = false;
                return;
            }
            m_i = 0;
            m_it.next();
            m_cardinality = m_it.cardinality();
            decode_chunk(m_it, m_buf.data());
        }
    }

    uint32_t value() const {
        return m_has_next ? m_buf[m_i] : m_past_the_end;
    }

private:
    s_sequence::iterator m_it;
    uint32_t m_chunk;
    uint32_t m_chunks;
    uint32_t m_i;
    uint32_t m_cardinality;
    uint32_t m_past_the_end;
    bool m_has_next;
    std::vector<uint32_t> m_buf;
};

}  // namespace sliced