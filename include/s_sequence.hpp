#pragma once

#include "constants.hpp"

namespace sliced {

struct s_sequence {
    s_sequence(uint8_t const* addr) {
        uint16_t const* ptr = reinterpret_cast<uint16_t const*>(addr);
        chunks = 1 + *ptr++;
        m_pointers = reinterpret_cast<uint32_t const*>(ptr);
        uint64_t pointers_bytes =
            chunks / constants::associativity * sizeof(uint32_t) * 2;
        uint64_t header_bytes = chunks * 4 * sizeof(uint16_t);
        m_header = ptr + pointers_bytes / sizeof(uint16_t);
        m_data = addr + sizeof(uint16_t) + pointers_bytes + header_bytes;
    }

    size_t decode(uint32_t* out);
    size_t uncompress(uint64_t* out);
    bool select(uint32_t rank, uint32_t& value);
    bool contains(uint32_t value);
    uint32_t next_geq(uint32_t value);

    uint32_t const* pointers() const {
        return m_pointers;
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
            : pointers(s.pointers())
            , header(s.header())
            , data(s.data())
            , begin(begin)
            , end(end) {}

        inline uint32_t id() const {
            return *header;
        }

        inline uint32_t base() const {
            return id() << 16;
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

        // can try SIMD here?
        void skip_to(uint32_t lower_bound) {
            while (skip_position() < end and *skip_header() <= lower_bound) {
                data += *(pointers + 1);
                pointers += 2;
                header = skip_header();
                begin = skip_position();
            }
            advance(lower_bound);
        }

        uint32_t advance_to(uint32_t rank) {
            uint32_t elements = 0;
            while (skip_position() < end) {
                uint32_t c = *pointers;
                if (elements + c > rank) {
                    break;
                }
                elements += c;
                data += *(pointers + 1);
                pointers += 2;
                header = skip_header();
                begin = skip_position();
            }

            while (has_next()) {
                uint32_t c = cardinality();
                if (elements + c > rank) {
                    return elements;
                }
                elements += c;
                next();
            }

            return elements;
        }

        uint32_t const* pointers;
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
    uint32_t const* m_pointers;
    uint16_t const* m_header;
    uint8_t const* m_data;
};

}  // namespace sliced