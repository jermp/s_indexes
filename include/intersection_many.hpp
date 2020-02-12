#pragma once

#include "uncompress_chunk_and_intersect.hpp"

namespace sliced {

inline uint32_t decode_bitmap65536(uint64_t const* bitmap, uint32_t base,
                                   uint32_t* out) {
    uint32_t size = 0;
    for (size_t i = 0; i != 1024; ++i) {
        uint64_t w = bitmap[i];
        while (w != 0) {
            uint64_t t = w & (~w + 1);
            int r = __builtin_ctzll(w);
            out[size++] = r + base;
            w ^= t;
        }
        base += 64;
    }
    return size;
}

size_t intersection(std::vector<s_sequence>& sequences, uint32_t* out) {
    uint32_t* in = out;
    std::sort(sequences.begin(), sequences.end(),
              [](auto const& l, auto const& r) {
                  return l.cardinality() < r.cardinality();
              });
    std::vector<s_sequence::iterator> iterators(sequences.size());
    for (size_t i = 0; i != sequences.size(); ++i) {
        iterators[i] = sequences[i].begin();
    }

    // 1. intersect headers
    static std::vector<uint16_t> headers(65536);
    uint64_t num_headers = 0;
    {
        uint32_t candidate = iterators[0].id();
        size_t i = 1;
        while (candidate < 65536) {
            for (; i < iterators.size(); ++i) {
                iterators[i].skip_to_value(candidate);
                uint32_t val = iterators[i].id();
                if (val != candidate) {
                    candidate = val;
                    i = 0;
                    break;
                }
            }

            if (i == iterators.size()) {
                headers[num_headers] = candidate;
                ++num_headers;
                iterators[0].next();
                candidate = iterators[0].id();
                i = 1;
            }
        }
    }

    // 2. perform AND with headers in common
    {
        for (size_t i = 0; i != sequences.size(); ++i) {
            iterators[i] = sequences[i].begin();
        }

        static std::vector<uint64_t> bitmap(1024);

        for (uint64_t i = 0; i != num_headers; ++i) {
            uint32_t header = headers[i];
            uint32_t base = header << 16;
            iterators[0].skip_to_value(header);
            assert(iterators[0].id() == header);
            uint32_t cardinality =
                uncompress_chunk(iterators[0], bitmap.data());
            assert(cardinality != 0);
            for (uint64_t i = 1; i != iterators.size(); ++i) {
                iterators[i].skip_to_value(header);
                assert(iterators[i].id() == header);
                cardinality = uncompress_chunk_and_intersect(
                    iterators[i], bitmap.data(), cardinality);
                if (cardinality == 0) break;
            }
            if (cardinality != 0) {
                size_t decoded = decode_bitmap65536(bitmap.data(), base, out);
                out += decoded;
            }
        }
    }

    return size_t(out - in);
}

}  // namespace sliced