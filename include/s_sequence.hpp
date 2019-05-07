#pragma once

#include "constants.hpp"

namespace sliced {

struct s_sequence {
    s_sequence(uint8_t const* addr) {
        uint16_t const* ptr = reinterpret_cast<uint16_t const*>(addr);
        chunks = 1 + *ptr++;
        m_offsets = reinterpret_cast<uint64_t const*>(ptr);
        uint64_t offsets_bytes =
            chunks / constants::associativity * sizeof(uint64_t);
        uint64_t header_bytes = chunks * 4 * sizeof(uint16_t);
        m_header = ptr + offsets_bytes / sizeof(uint16_t);
        m_data = addr + sizeof(uint16_t) + offsets_bytes + header_bytes;
    }

    size_t decode(uint32_t* out);
    size_t uncompress(uint64_t* out);
    bool select(uint32_t rank, uint32_t& value);
    bool contains(uint32_t value);
    uint32_t next_geq(uint32_t value);

    uint64_t const* offsets() const {
        return m_offsets;
    }

    uint16_t const* header() const {
        return m_header;
    }

    uint8_t const* data() const {
        return m_data;
    }

    uint32_t cardinality() const {
        auto const* h = header();
        uint32_t c = 0;
        for (uint32_t i = 0; i != chunks; ++i) {
            c += *(h + 1) + 1;
            h += 4;
        }
        return c;
    }

    struct iterator {
        iterator(s_sequence const& s, uint32_t begin, uint32_t end)
            : offsets(s.offsets())
            , header(s.header())
            , data(s.data())
            , begin(begin)
            , end(end) {}

        inline uint32_t id() const {
            return *header;
        }

        inline uint32_t cardinality() const {
            return *(header + 1) + 1;
        }

        inline uint32_t type() const {
            return *(header + 2) & 255;
        }

        inline uint32_t blocks() const {
            return (*(header + 2) >> 8) + 1;
        }

        inline uint32_t offset() const {
            return *(header + 3);
        }

        inline void next() {
            data += offset();
            header += 4;
            begin += 1;
        }

        inline bool has_next() const {
            return begin < end;
        }

        void advance(uint32_t lower_bound) {
            while (id() < lower_bound and has_next()) {
                next();
            }
        }

        void skip_to(uint32_t lower_bound) {
            while (skip_position() < end and *skip_header() <= lower_bound) {
                data += *offsets++;
                header = skip_header();
                begin = skip_position();
            }
            advance(lower_bound);
        }

        uint64_t const* offsets;
        uint16_t const* header;
        uint8_t const* data;
        uint32_t begin;
        const uint32_t end;

    private:
        inline uint32_t skip_position() const {
            return begin + constants::associativity;
        }

        inline uint16_t const* skip_header() const {
            return header + 4 * constants::associativity;
        }
    };

    iterator begin() const {
        return iterator(*this, 0, chunks);
    }

    uint32_t chunks;

private:
    uint64_t const* m_offsets;
    uint16_t const* m_header;
    uint8_t const* m_data;
};

}  // namespace sliced