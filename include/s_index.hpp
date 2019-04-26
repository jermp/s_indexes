#pragma once

#include <cassert>
#include <vector>

#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "s_sequence.hpp"

namespace sliced {

struct s_index {
    struct builder1;
    // struct builder2;

    size_t size() const {
        // return m_offsets.size();
        return m_size;
    }

    s_sequence operator[](size_t i) {
        assert(i < size());
        // return s_sequence(&m_sequences[m_offsets[i]]);

        return s_sequence(m_sequences_ptr + m_offsets_ptr[i]);
    }

    template <typename Visitor>
    void visit(Visitor& visitor) {
        visitor.visit(m_offsets);
        visitor.visit(m_sequences);
    }

    void mmap(char const* binary_filename) {
        m_input.open(binary_filename, mm::advice::sequential);
        auto ptr = reinterpret_cast<uint64_t const*>(m_input.data());
        m_size = *ptr++;
        m_offsets_ptr = ptr;
        m_sequences_ptr =
            m_input.data() + (m_size + 1) * sizeof(uint64_t) + sizeof(uint64_t);
    }

private:
    std::vector<uint64_t> m_offsets;
    std::vector<uint8_t> m_sequences;

    mm::file_source<uint8_t> m_input;
    uint64_t const* m_offsets_ptr;
    uint8_t const* m_sequences_ptr;
    uint64_t m_size;
};

}  // namespace sliced