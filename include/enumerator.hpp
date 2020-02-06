#pragma once

#include "decode.hpp"

namespace sliced {

struct enumerator {
    enumerator() {
        m_buf.resize(constants::chunk_size);
    }

    void init(s_sequence const& s, uint64_t past_the_end) {
        m_it = s.begin();
        m_chunk = 0;
        m_chunks = s.chunks;
        m_i = 0;
        m_cardinality = m_it.cardinality();
        decode_chunk(m_it, m_buf.data());
        m_past_the_end = past_the_end;
    }

    uint64_t next() {
        if (m_i == m_cardinality) {
            if (m_chunk == m_chunks) return m_past_the_end;
            m_i = 0;
            m_it.next();
            m_cardinality = m_it.cardinality();
            decode_chunk(m_it, m_buf.data());
            ++m_chunk;
        }
        return m_buf[m_i++];
    }

private:
    s_sequence::iterator m_it;
    uint32_t m_chunk;
    uint32_t m_chunks;
    uint32_t m_i;
    uint32_t m_cardinality;
    uint64_t m_past_the_end;
    std::vector<uint32_t> m_buf;
};

}  // namespace sliced