#pragma once

#include "decode.hpp"
#include "uncompress_chunk_and_merge.hpp"

namespace sliced {

size_t union_many(std::vector<s_sequence>& sequences, uint32_t* out) {
    uint32_t* in = out;
    std::vector<s_sequence::iterator> iterators(sequences.size());
    for (size_t i = 0; i != sequences.size(); ++i) {
        iterators[i] = sequences[i].begin();
    }

    static std::vector<uint64_t> bitmap(1024);
    uint32_t header = std::min_element(iterators.begin(), iterators.end(),
                                       [](auto const& l, auto const& r) {
                                           return l.id() < r.id();
                                       })
                          ->id();
    bool first = true;
    while (header < 65536) {
        uint32_t base = header << 16;
        for (size_t i = 0; i != iterators.size(); ++i) {
            if (iterators[i].id() == header) {
                if (first) {
                    uncompress_chunk(iterators[i], bitmap.data());
                    first = false;
                } else {
                    uncompress_chunk_and_merge(iterators[i], bitmap.data());
                }
            }
        }
        first = true;
        out += decode_bitmap(bitmap.data(), 1024, base, out);
        uint32_t next = 65536;
        for (size_t i = 0; i != iterators.size(); ++i) {
            if (iterators[i].id() == header) iterators[i].next();
            if (iterators[i].id() < next) next = iterators[i].id();
        }
        header = next;
    }

    return size_t(out - in);
}

}  // namespace sliced