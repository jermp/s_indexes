#pragma once

#include <cassert>
#include <vector>

#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "s_sequence.hpp"

namespace sliced {

struct s_index {
    struct builder1;
    struct builder2;

    inline size_t size() const {
        return m_size;
    }

    s_sequence operator[](size_t i) {
        assert(i < size());
        return s_sequence(m_sequences + m_offsets[i]);
    }

    void mmap(char const* binary_filename) {
        m_input.open(binary_filename, mm::advice::sequential);
        auto ptr = reinterpret_cast<uint64_t const*>(m_input.data());
        m_size = *ptr++;
        m_offsets = ptr;
        m_sequences =
            m_input.data() + (m_size + 1) * sizeof(uint64_t) + sizeof(m_size);
    }

private:
    mm::file_source<uint8_t> m_input;
    uint64_t const* m_offsets;
    uint8_t const* m_sequences;
    uint64_t m_size;
};

}  // namespace sliced