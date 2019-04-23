#pragma once

namespace sliced {

struct s_sequence {
    s_sequence(uint8_t const* addr) {
        uint16_t const* ptr = reinterpret_cast<uint16_t const*>(addr);
        chunks = *ptr++;
        m_header = ptr;
        m_data = addr + sizeof(uint16_t) + chunks * 3 * sizeof(uint16_t);
    }

    size_t decode(uint32_t* out);

    size_t uncompress(uint64_t* out);

    uint16_t const* header() const {
        return m_header;
    }

    uint8_t const* data() const {
        return m_data;
    }

    struct iterator {
        iterator(s_sequence const& s, uint32_t begin, uint32_t end)
            : header(s.header())
            , data(s.data())
            , position(begin)
            , end(end) {}

        inline uint16_t id() const {
            return *header;
        }

        inline uint16_t type() const {
            return *(header + 1);
        }

        inline uint16_t offset() const {
            return *(header + 2);
        }

        inline void next() {
            data += offset();
            header += 3;
            position += 1;
        }

        bool has_next() const {
            return position < end;
        }

        void advance(uint32_t lower_bound) {
            while (id() < lower_bound and position < end) {
                next();
            }
        }

        uint16_t const* header;
        uint8_t const* data;
        uint32_t position;
        uint32_t end;
    };

    iterator begin() {
        return iterator(*this, 0, chunks);
    }

    uint32_t chunks;

private:
    uint16_t const* m_header;
    uint8_t const* m_data;
};

}  // namespace sliced