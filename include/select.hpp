#pragma once

namespace sliced {

uint32_t select_bitmap(uint8_t const* data, size_t size_in_64bit_words,
                       uint32_t rank) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(data);
    uint32_t elements = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
        int c = __builtin_popcountll(w);
        if (elements + c > rank) {
            uint32_t base = i * 64;
            while (w != 0) {
                uint64_t t = w & (~w + 1);
                int r = __builtin_ctzll(w);
                if (elements == rank) {
                    return r + base;
                }
                w ^= t;
                ++elements;
            }
        }
        elements += c;
    }
    assert(false);
    __builtin_unreachable();
    return elements;
}

uint32_t select_sparse_chunk(uint8_t const* begin, int blocks, uint32_t rank) {
    assert(blocks >= 1 and blocks <= 256);
    uint8_t const* data = begin + blocks * 2;
    uint8_t const* end = data;
    uint32_t elements = 0;
    while (begin != end) {
        uint8_t id = *begin;
        int c = *(begin + 1) + 1;
        int bytes = 32;
        int type = type::dense;
        if (LIKELY(c < 31)) {
            bytes = c;
            type = type::sparse;
        }
        if (elements + c > rank) {
            rank -= elements;
            assert(int(rank) < c);
            uint32_t base = id * 256;
            if (type == type::sparse) {
                return *(data + rank) + base;
            } else {
                return select_bitmap(data, constants::block_size_in_64bit_words,
                                     rank) +
                       base;
            }
        }
        elements += c;
        data += bytes;
        begin += 2;
    }
    assert(false);
    __builtin_unreachable();
    return elements;
}

bool s_sequence::select(uint32_t rank, uint32_t& value) {
    uint32_t elements = 0;
    auto it = begin();
    bool valid = false;

    while (it.has_next()) {
        uint32_t c = it.cardinality();
        if (elements + c > rank) {
            valid = true;
            break;
        }
        elements += c;
        it.next();
    }

    if (valid) {
        rank -= elements;
        assert(rank < constants::chunk_size);
        uint32_t base = it.id() << 16;
        switch (it.type()) {
            case type::sparse:
                value = select_sparse_chunk(it.data, it.blocks(), rank);
                break;
            case type::dense:
                value = select_bitmap(
                    it.data, constants::chunk_size_in_64bit_words, rank);
                break;
            case type::full:
                value = rank;
                break;
            default:
                assert(false);
                __builtin_unreachable();
        }

        value += base;
        return true;
    } else {
        return false;
    }
}

}  // namespace sliced