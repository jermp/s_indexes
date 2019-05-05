#pragma once

namespace sliced {

struct s_sequence {
    s_sequence(uint8_t const* addr) {
        uint16_t const* ptr = reinterpret_cast<uint16_t const*>(addr);
        chunks = 1 + *ptr++;
        m_header = ptr;
        m_data = addr + sizeof(uint16_t) + chunks * 4 * sizeof(uint16_t);
    }

    size_t decode(uint32_t* out);
    size_t uncompress(uint64_t* out);
    bool select(uint32_t rank, uint32_t& value);

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
            : header(s.header())
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

        bool has_next() const {
            return begin < end;
        }

        void advance(uint32_t lower_bound) {
            while (id() < lower_bound and begin < end) {
                next();
            }
        }

        uint16_t const* header;
        uint8_t const* data;
        uint32_t begin;
        uint32_t end;
    };

    iterator begin() const {
        return iterator(*this, 0, chunks);
    }

    uint32_t chunks;

private:
    uint16_t const* m_header;
    uint8_t const* m_data;
};

}  // namespace sliced