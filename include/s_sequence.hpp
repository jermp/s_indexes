#pragma once

namespace sliced {

struct s_sequence {
    s_sequence(uint8_t const* begin) : m_begin(begin) {}

    size_t decode(uint32_t* out);

    size_t uncompress(uint64_t* out);

private:
    uint8_t const* m_begin;
};

}  // namespace sliced