#pragma once

#include <iostream>
#include <cassert>
#include <vector>

#include "util.hpp"
#include "configuration.hpp"
#include "builders.hpp"
#include "s_sequence.hpp"

#include "../external/mm_file/include/mm_file/mm_file.hpp"

namespace sliced {

struct s_index {
    struct builder {
        builder(parameters const& params) : m_params(params) {}

        statistics build(s_index& index) {
            mm::file_source<uint32_t> input(m_params.collection_filename,
                                            mm::advice::sequential);
            uint32_t const* data = input.data();
            std::vector<uint32_t> block;
            block.reserve(constants::block_size);
            statistics stats;

            assert(data[0] == 1);
            std::cout << "universe size: " << data[1] << std::endl;

            std::vector<uint64_t> offsets;
            std::vector<uint8_t> sequences;
            offsets.push_back(0);

            // uint32_t k = 0;
            for (size_t i = 2;  // first two values reserved for a singleton
                                // sequence containing the universe size
                 i < input.size();) {
                uint32_t n = data[i];
                uint32_t universe = data[i + n];
                if (double(n) / universe > m_params.density) {
                    // if (k == 5939) {
                    encode_sequence(data + i + 1, n, block, stats, sequences);
                    offsets.push_back(sequences.size());
                    if (stats.sequences % 1000 == 0) {
                        std::cout << "processed " << stats.sequences
                                  << " sequences" << std::endl;
                    }
                    // }
                    // ++k;
                }
                i += n + 1;
            }

            stats.chunks_header_bits =
                (stats.full_chunks + stats.sparse_chunks + stats.dense_chunks) *
                    16 * 3 +
                stats.sequences * 16  // for the number of chunks
                ;
            stats.blocks_header_bits = stats.blocks * 2;
            stats.bits = stats.chunks_header_bits + stats.blocks_header_bits +
                         stats.dense_chunks_bits + stats.dense_blocks_bits +
                         stats.sparse_blocks_bits;

            std::cout << "offsets " << offsets.size() * sizeof(offsets.front())
                      << " bytes" << std::endl;
            std::cout << "sequences " << sequences.size() << " bytes"
                      << std::endl;

            index.m_offsets.swap(offsets);
            index.m_sequences.swap(sequences);

            return stats;
        }

    private:
        parameters const& m_params;
    };

    s_index() {}

    size_t size() const {
        return m_offsets.size();
    }

    s_sequence operator[](size_t i) {
        assert(i < size());
        return s_sequence(&m_sequences[m_offsets[i]]);
    }

    template <typename Visitor>
    void visit(Visitor& visitor) {
        visitor.visit(m_offsets);
        visitor.visit(m_sequences);
    }

private:
    std::vector<uint64_t> m_offsets;
    std::vector<uint8_t> m_sequences;
};

}  // namespace sliced