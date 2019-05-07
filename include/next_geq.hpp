#pragma once

namespace sliced {

uint32_t next_geq_sparse_block(uint8_t const* begin, int cardinality,
                               uint32_t value) {
    // NOTE: maybe can use SIMD here
    for (int i = 0; i != cardinality; ++i) {
        if (begin[i] >= value) {
            return begin[i];
        }
    }
    return -1;
}

uint32_t max_value_in_bitmap(uint8_t const* data, size_t size_in_64bit_words) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(data);
    for (int32_t i = size_in_64bit_words - 1; i >= 0; --i) {
        uint64_t w = bitmap[i];
        if (w != 0) {
            int r = __builtin_clzll(w);
            return i * 64 + 63 - r;
        }
    }
    return 0;
}

uint32_t min_value_in_bitmap(uint8_t const* data, size_t size_in_64bit_words) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(data);
    for (uint32_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
        if (w != 0) {
            return i * 64 + __builtin_clzll(w);
        }
    }
    return 0;
}

uint32_t next_geq_bitmap(uint8_t const* data, uint32_t size_in_64bit_words,
                         uint32_t value) {
    uint64_t const* bitmap = reinterpret_cast<uint64_t const*>(data);
    uint32_t k = value / 64;
    uint64_t word = bitmap[k];
    const int diff = value - k * 64;
    word = (word >> diff) << diff;
    while (word == 0) {
        k++;
        if (k == size_in_64bit_words) {
            return -1;
        }
        word = bitmap[k];
    }
    return k * 64 + __builtin_ctzll(word);
}

uint32_t max_value_in_block(uint8_t const* begin, uint8_t const* data) {
    int c = *(begin + 1) + 1;
    if (LIKELY(c < 31)) {  // block type is sparse
        return *(data + c - 1);
    }
    return max_value_in_bitmap(data, constants::block_size_in_64bit_words);
}

uint32_t next_geq_sparse_chunk(uint8_t const* begin, int blocks,
                               uint32_t value) {
    assert(blocks >= 1 and blocks <= 256);
    uint8_t const* data = begin + blocks * 2;
    uint8_t const* end = data;
    uint32_t block_id = value >> 8;
    uint32_t id = 0;

    while (begin != end) {
        id = *begin;
        if (id >= block_id) {
            break;
        }
        int c = *(begin + 1) + 1;
        data += BYTES_BY_CARDINALITY(c);
        begin += 2;
    }

    if (begin != end) {
        uint32_t lower_bound = value & 0xFF;
        uint32_t upper_bound = max_value_in_block(begin, data);
        if (lower_bound > upper_bound) {
            int c = *(begin + 1) + 1;
            data += BYTES_BY_CARDINALITY(c);
            begin += 2;
            id = *begin;
            value = id * 256;
        }

        uint32_t base = id * 256;
        if (value > base) {
            value -= base;
        } else {
            value = 0;
        }

        int c = *(begin + 1) + 1;
        if (LIKELY(c < 31)) {  // block type is sparse
            return next_geq_sparse_block(data, c, value) + base;
        }
        return next_geq_bitmap(data, constants::block_size_in_64bit_words,
                               value) +
               base;
    }

    return -1;
}

// uint32_t max_value_in_sparse_chunk(uint8_t const* begin, int blocks) {
//     assert(blocks >= 1 and blocks <= 256);
//     uint8_t const* data = begin + blocks * 2;
//     uint32_t id = *begin;
//     int c = *(begin + 1) + 1;

//     for (int i = 1; i != blocks; ++i) {
//         data += BYTES_BY_CARDINALITY(c);
//         begin += 2;
//         id = *begin;
//         c = *(begin + 1) + 1;
//     }

//     uint32_t base = id * 256;
//     if (LIKELY(c < 31)) {  // block type is sparse
//         return *(data + c - 1) + base;
//     }
//     return max_value_in_bitmap(data, constants::block_size_in_64bit_words) +
//            base;
// }

// uint32_t max_value_in_chunk(s_sequence::iterator const& it) {
//     uint32_t type = it.type();
//     if (type == type::sparse) {
//         return max_value_in_sparse_chunk(it.data, it.blocks());
//     } else if (type == type::dense) {
//         return max_value_in_bitmap(it.data,
//                                    constants::chunk_size_in_64bit_words);
//     }
//     return constants::chunk_size;
// }

uint32_t min_value_in_sparse_chunk(uint8_t const* begin, int blocks) {
    assert(blocks >= 1 and blocks <= 256);
    uint8_t const* data = begin + blocks * 2;
    uint32_t id = *begin;
    int c = *(begin + 1) + 1;
    uint32_t base = id * 256;
    if (LIKELY(c < 31)) {  // block type is sparse
        return *data + base;
    }
    return min_value_in_bitmap(data, constants::block_size_in_64bit_words) +
           base;
}

uint32_t s_sequence::next_geq(uint32_t value) {
    auto it = begin();
    uint32_t chunk_id = value >> 16;
    // it.advance(chunk_id);

    it.skip_to(chunk_id);

    if (it.has_next()) {
        // uint32_t lower_bound = value & 0xFFFF;
        // uint32_t upper_bound = max_value_in_chunk(it);
        // if (lower_bound > upper_bound) {
        //     it.next();
        //     value = it.id() << 16;
        // }
        // uint32_t base = it.id() << 16;
        // assert(value >= base);
        // value -= base;
        // switch (it.type()) {
        //     case type::sparse:
        //         value = next_geq_sparse_chunk(it.data, it.blocks(), value);
        //         break;
        //     case type::dense:
        //         value = next_geq_bitmap(it.data, value);
        //         break;
        //     case type::full:
        //         break;
        //     default:
        //         assert(false);
        //         __builtin_unreachable();
        // }
        // return value + base;

        uint32_t base = it.id() << 16;
        assert(value >= base);
        uint32_t ret = 0;
        switch (it.type()) {
            case type::sparse:
                ret = next_geq_sparse_chunk(it.data, it.blocks(), value - base);
                break;
            case type::dense:
                ret = next_geq_bitmap(it.data,
                                      constants::chunk_size_in_64bit_words,
                                      value - base);
                break;
            case type::full:
                ret = value - base;
                break;
            default:
                assert(false);
                __builtin_unreachable();
        }

        if (ret == uint32_t(-1)) {
            it.next();
            value = it.id() << 16;
        } else {
            return ret + base;
        }

        base = it.id() << 16;
        switch (it.type()) {
            case type::sparse:
                value = min_value_in_sparse_chunk(it.data, it.blocks());
                break;
            case type::dense:
                value = min_value_in_bitmap(
                    it.data, constants::chunk_size_in_64bit_words);
                break;
            case type::full:
                value = 0;
                break;
            default:
                assert(false);
                __builtin_unreachable();
        }

        return value + base;
    }

    return -1;
}

}  // namespace sliced