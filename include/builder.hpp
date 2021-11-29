#pragma once

#include <iostream>
#include <cassert>
#include <vector>

#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "s_index.hpp"
#include "util.hpp"
#include "building_util.hpp"

namespace sliced {

void encode_block(std::vector<uint32_t>& block, uint32_t& id,
                  std::vector<uint8_t>& header, std::vector<uint8_t>& data) {
    if (block.size() > 0) {
        write_uint<uint8_t>(id, header);
        write_uint<uint8_t>(block.size() - 1, header);
        if (block.size() >= constants::block_sparseness_threshold - 1) {
            write_bits(block.data(), block.size(), constants::block_size, 0,
                       data);
        } else {
            for (auto pos : block) write_uint<uint8_t>(pos, data);
        }
        block.clear();
    }
    id += 1;
}

void encode_sparse_chunk(uint32_t const* begin, uint32_t const* end, slice s,
                         std::vector<uint32_t>& block,
                         std::vector<uint8_t>& out) {
    std::vector<uint8_t> header;
    std::vector<uint8_t> data;
    header.reserve(256 * 2);  // at most
    data.reserve(256 * 32);   // at most
    uint32_t id = 0;
    uint32_t base = s.left;
    while (begin != end and *begin < s.right) {
        uint32_t val = *begin - base;
        if (val >= constants::block_size) {
            encode_block(block, id, header, data);
            base += constants::block_size;
        } else {
            assert(val < constants::block_size);
            block.push_back(val);
            assert(block.size() <= constants::block_size);
            ++begin;
        }
    }
    encode_block(block, id, header, data);
    out.insert(out.end(), header.begin(), header.end());
    out.insert(out.end(), data.begin(), data.end());
}

void encode_sequence(uint32_t const* data, size_t n,
                     std::vector<uint32_t>& block, statistics& stats,
                     std::vector<uint8_t>& out) {
    assert(block.empty());
    auto begin = data;
    auto end = data + n;
    uint32_t universe = *(data + n - 1);
    uint32_t chunks = num_chunks(universe);
    assert(chunks > 0 and chunks <= constants::chunk_size);

    stats.sequences += 1;
    stats.integers += n;
    stats.chunks += chunks;

    std::vector<uint16_t> chunks_header;
    chunks_header.reserve(4 * constants::chunk_size);  // at most
    std::vector<uint8_t> tmp;

    const uint32_t dense_chunk_bytes = bytes_for(constants::chunk_size);
    slice s = {0, constants::chunk_size};

    for (uint32_t i = 0; i != chunks; ++i) {
        uint32_t cardinality = 0;
        if (*begin < s.right) {
            cardinality = chunk_cardinality(begin, end, s);
            chunks_header.push_back(i);
            chunks_header.push_back(cardinality - 1);

            if (cardinality < constants::chunk_sparseness_threshold) {
                auto sparse_chunk_stats = sparse_chunk_bitsize(begin, end, s);

                uint64_t sparse_chunk_bytes =
                    (sparse_chunk_stats.dense_blocks * 16 +
                     // NOTE: the 8 bits for the cardinality of sparse
                     // blocks are already accounted in sparse_blocks_bits
                     sparse_chunk_stats.sparse_blocks * 8 +
                     sparse_chunk_stats.dense_blocks_bits +
                     sparse_chunk_stats.sparse_blocks_bits) /
                    8;

                if (sparse_chunk_bytes >= dense_chunk_bytes) {
                    stats.dense_chunks += 1;
                    stats.dense_chunks_bits += dense_chunk_bytes * 8;
                    stats.integers_in_dense_chunks += cardinality;
                    chunks_header.push_back(type::dense);
                    chunks_header.push_back(constants::chunk_size / 8);
                    write_bits(begin, cardinality, constants::chunk_size,
                               s.left, tmp);
                } else {
                    stats.sparse_chunks += 1;
                    stats.integers_in_sparse_chunks += cardinality;

                    uint16_t num_non_empty_blocks =
                        sparse_chunk_stats.dense_blocks +
                        sparse_chunk_stats.sparse_blocks;
                    assert(num_non_empty_blocks >= 1 and
                           num_non_empty_blocks <= 256);
                    stats.blocks +=
                        num_non_empty_blocks + sparse_chunk_stats.empty_blocks;

                    stats.accumulate(sparse_chunk_stats);

                    uint16_t packed = type::sparse;
                    packed |= (num_non_empty_blocks - 1) << 8;
                    chunks_header.push_back(packed);

                    chunks_header.push_back(sparse_chunk_bytes);

                    encode_sparse_chunk(begin, end, s, block, tmp);
                }

            } else {
                if (cardinality == constants::chunk_size) {
                    stats.full_chunks += 1;
                    stats.integers_in_full_chunks += cardinality;
                    chunks_header.push_back(type::full);
                    chunks_header.push_back(0);
                } else {
                    stats.dense_chunks += 1;
                    stats.dense_chunks_bits += dense_chunk_bytes * 8;
                    stats.integers_in_dense_chunks += cardinality;
                    assert(dense_chunk_bytes * 8.0 / cardinality <= 2.0);
                    chunks_header.push_back(type::dense);
                    chunks_header.push_back(constants::chunk_size / 8);
                    write_bits(begin, cardinality, constants::chunk_size,
                               s.left, tmp);
                }
            }

        } else {
            stats.empty_chunks += 1;
        }

        s.left = s.right;
        s.right += constants::chunk_size;
        begin += cardinality;
    }

    assert(begin == end);
    chunks = chunks_header.size() / 4;
    write_uint<uint16_t>(chunks - 1, out);

    // write chunks / constants::associativity pointers
    // NOTE: a pointer is
    // cardinality | byte_offset
    // -----------   -----------
    //   32 bits       32 bits
    uint64_t offsets = chunks / constants::associativity;
    uint32_t offset = 0;
    uint32_t cardinality = 0;
    for (uint64_t i = 0; i != offsets; ++i) {
        uint32_t base = i * 4 * constants::associativity;
        offset = 0;
        cardinality = 0;
        for (uint32_t j = 1; j != constants::associativity + 1; ++j) {
            cardinality += chunks_header[base + 1] + 1;
            offset += chunks_header[base + 3];
            base += 4;
        }
        write_uint<uint32_t>(cardinality, out);
        write_uint<uint32_t>(offset, out);
    }

    auto ptr = reinterpret_cast<uint8_t const*>(chunks_header.data());
    out.insert(out.end(), ptr,
               ptr + chunks_header.size() * sizeof(chunks_header.front()));
    out.insert(out.end(), tmp.begin(), tmp.end());

    stats.chunks_header_bits += chunks * 16 * 4 + 16 +
                                offsets * sizeof(offset) * 8 +
                                offsets * sizeof(cardinality) * 8;
}

statistics encode_sequence(uint32_t const* data, size_t n,
                           std::vector<uint8_t>& out) {
    std::vector<uint32_t> block;
    block.reserve(constants::block_size);
    statistics stats;

    encode_sequence(data, n, block, stats, out);

    stats.blocks_header_bits =
        stats.dense_blocks * 16 + stats.sparse_blocks * 8;
    stats.bits = stats.chunks_header_bits + stats.blocks_header_bits +
                 stats.dense_chunks_bits + stats.dense_blocks_bits +
                 stats.sparse_blocks_bits;

    stats.bits += 2 * 64;

    return stats;
}

struct s_index::builder {
    builder(parameters const& params)
        : m_params(params) {}

    statistics build() {
        mm::file_source<uint32_t> input(m_params.collection_filename,
                                        mm::advice::sequential);
        uint32_t const* data = input.data();
        std::vector<uint32_t> block;
        block.reserve(constants::block_size);
        statistics stats;

        assert(data[0] == 1);
        std::cout << "universe size: " << data[1] << std::endl;

        m_offsets.push_back(data[1]);
        m_offsets.push_back(0);

        for (size_t i = 2;  // first two values reserved for a singleton
                            // sequence containing the universe size
             i < input.size();) {
            uint32_t n = data[i];
            uint32_t universe = data[i + n];
            if (pass(m_params, n, universe)) {
                encode_sequence(data + i + 1, n, block, stats, m_sequences);
                m_offsets.push_back(m_sequences.size());
                if (stats.sequences % 1000 == 0) {
                    std::cout << "processed " << stats.sequences << " sequences"
                              << std::endl;
                }
            }
            i += n + 1;
        }

        m_offsets.pop_back();

        stats.blocks_header_bits =
            stats.dense_blocks * 16 + stats.sparse_blocks * 8;
        stats.bits = stats.chunks_header_bits + stats.blocks_header_bits +
                     stats.dense_chunks_bits + stats.dense_blocks_bits +
                     stats.sparse_blocks_bits;

        stats.bits += 2 * 64;
        stats.bits += m_offsets.size() * 64;

        return stats;
    }

    template <typename Visitor>
    void visit(Visitor& visitor) {
        visitor.visit(m_offsets);
        visitor.visit(m_sequences);
    }

private:
    parameters const& m_params;
    std::vector<uint64_t> m_offsets;
    std::vector<uint8_t> m_sequences;
};

struct s_sequence::builder {
    builder() {}

    statistics build(uint32_t const* data, size_t n) {
        return encode_sequence(data, n, m_out);
    }

    uint8_t const* data() const {
        return m_out.data();
    }

    template <typename Visitor>
    void visit(Visitor& visitor) {
        visitor.visit(m_out);
    }

private:
    std::vector<uint8_t> m_out;
};
}  // namespace sliced