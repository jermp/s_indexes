#pragma once

#include "decode.hpp"
#include "uncompress_chunk_and_intersect.hpp"

namespace sliced {

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
                headers[num_headers++] = candidate;
                iterators[0].next();
                candidate = iterators[0].id();
                i = 1;
            }
        }
    }

    {
        for (size_t i = 0; i != sequences.size(); ++i) {
            iterators[i] = sequences[i].begin();
        }

        static std::vector<uint64_t> bitmap(1024);

        for (uint64_t i = 0; i != num_headers; ++i) {
            uint32_t header = headers[i];
            uint32_t base = header << 16;

            // std::sort(iterators.begin(), iterators.end(),
            //           [](auto const& l, auto const& r) {
            //               return l.cardinality() < r.cardinality();
            //           });

            iterators[0].advance(header);
            assert(iterators[0].id() == header);
            uint32_t cardinality =
                uncompress_chunk(iterators[0], bitmap.data());
            for (uint64_t i = 1; i != iterators.size(); ++i) {
                iterators[i].advance(header);
                assert(iterators[i].id() == header);
                cardinality = uncompress_chunk_and_intersect(
                    iterators[i], bitmap.data(), cardinality);
                if (cardinality == 0) goto SKIP;
            }
            out += decode_bitmap(bitmap.data(), 1024, base, out);
        SKIP:;
        }
    }

    return size_t(out - in);
}

}  // namespace sliced