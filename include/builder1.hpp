#pragma once

#include <iostream>
#include <cassert>
#include <vector>

#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "s_index.hpp"
#include "util.hpp"
#include "building_util.hpp"

namespace sliced {

void write_header(uint32_t i, size_t offset, std::vector<uint8_t>& out,
                  uint32_t type) {
    assert(i < 256);
    size_t b = i / 4;
    size_t o = i % 4;
    out[offset + b] |= type << (o * 2);
}

void block_bitsize(size_t block_size, statistics& stats) {
    stats.blocks += 1;
    assert(block_size <= constants::block_size);
    if (block_size == 0) {
        stats.empty_blocks += 1;

        // NOTE: uncomment this if we want also full blocks
        // } else if (block_size == constants::block_size) {
        //     stats.full_blocks += 1;
        //     stats.integers_in_full_blocks += constants::block_size;

    } else if (block_size >= constants::block_sparseness_threshold - 1) {
        stats.dense_blocks += 1;
        stats.dense_blocks_bits += constants::block_size;
        stats.integers_in_dense_blocks += block_size;
    } else {
        assert(block_size <= constants::block_sparseness_threshold - 2);
        stats.sparse_blocks += 1;
        stats.integers_in_sparse_blocks += block_size;
        stats.sparse_blocks_bits += 8 * (block_size + 1);
    }
}

void encode_block(std::vector<uint32_t>& block, uint32_t& block_id,
                  size_t header_offset, std::vector<uint8_t>& out) {
    if (block.size() > 0) {
        // NOTE: uncomment this if we want also full blocks
        // if (block.size() == constants::block_size) {
        //     write_header(block_id, header_offset, out, type::full);
        // } else

        if (block.size() >= constants::block_sparseness_threshold - 1) {
            write_header(block_id, header_offset, out, type::dense);
            write_bits(block.data(), block.size(), constants::block_size, 0,
                       out);
        } else {
            write_header(block_id, header_offset, out, type::sparse);
            write_uint<uint8_t>(block.size(), out);
            for (auto pos : block) {
                write_uint<uint8_t>(pos, out);
            }
        }
        block.clear();
    }

    block_id += 1;
}

statistics chunk_bitsize(uint32_t const* begin, uint32_t const* end, slice s) {
    statistics stats;
    uint32_t base = s.left;
    size_t block_size = 0;
    while (*begin < s.right and begin != end) {
        uint32_t val = *begin - base;
        if (val >= constants::block_size) {
            block_bitsize(block_size, stats);
            base += constants::block_size;
            block_size = 0;
        } else {
            assert(val < constants::block_size);
            ++block_size;
            assert(block_size <= constants::block_size);
            ++begin;
        }
    }
    block_bitsize(block_size, stats);

    return stats;
}

void encode_sparse_chunk(uint32_t const* begin, uint32_t const* end, slice s,
                         std::vector<uint32_t>& block,
                         std::vector<uint8_t>& out) {
    size_t header_offset = out.size();
    uint64_t empty[8] = {0};
    auto ptr = reinterpret_cast<uint8_t const*>(empty);
    out.insert(out.end(), ptr, ptr + 8 * sizeof(uint64_t));

    uint32_t block_id = 0;
    uint32_t base = s.left;
    while (*begin < s.right and begin != end) {
        uint32_t val = *begin - base;
        if (val >= constants::block_size) {
            encode_block(block, block_id, header_offset, out);
            base += constants::block_size;
        } else {
            assert(val < constants::block_size);
            block.push_back(val);
            assert(block.size() <= constants::block_size);
            ++begin;
        }
    }
    encode_block(block, block_id, header_offset, out);
}

void encode_sequence(uint32_t const* data, size_t n,
                     std::vector<uint32_t>& block, statistics& stats,
                     std::vector<uint8_t>& out) {
    assert(block.empty());
    auto begin = data;
    auto end = data + n;
    uint32_t universe = *(data + n - 1);
    uint32_t chunks = universe ? (universe + constants::chunk_size - 1) /
                                     constants::chunk_size
                               : 1;
    assert(chunks > 0 and chunks < constants::chunk_size);
    uint32_t blocks_in_chunk = constants::chunk_size / constants::block_size;

    stats.sequences += 1;
    stats.integers += n;
    stats.chunks += chunks;

    std::vector<uint16_t> chunks_header;
    chunks_header.reserve(3 * constants::chunk_size);
    std::vector<uint8_t> tmp;

    slice s = {0, constants::chunk_size};

    for (uint32_t i = 0; i != chunks; ++i) {
        uint32_t cardinality = 0;
        if (*begin < s.right) {
            cardinality = chunk_cardinality(begin, end, s);

            // actual chunk universe
            // uint32_t chunk_universe = *(begin - 1) - base + 1;

            uint32_t chunk_universe = constants::chunk_size;
            uint32_t dense_chunk_bytes = bytes_for(chunk_universe);
            assert(dense_chunk_bytes * 8 <= constants::chunk_size);
            assert(cardinality <= constants::chunk_size);
            assert(chunk_universe <= constants::chunk_size);
            assert(cardinality <= chunk_universe);

            chunks_header.push_back(i);

            if (cardinality < constants::chunk_sparseness_threshold) {
                auto sparse_chunk_stats = chunk_bitsize(begin, end, s);

                uint64_t sparse_chunk_bytes =
                    (2 * blocks_in_chunk +
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

                    stats.blocks += blocks_in_chunk;
                    assert(sparse_chunk_stats.blocks <= blocks_in_chunk);
                    stats.empty_blocks +=
                        blocks_in_chunk - sparse_chunk_stats.blocks;

                    stats.accumulate(sparse_chunk_stats);

                    chunks_header.push_back(type::sparse);
                    chunks_header.push_back(sparse_chunk_bytes);

                    // std::cout << sparse_chunk_bytes * 8.0 / cardinality
                    //           << " [bpi] in sparse chunk\n";
                    // if (sparse_chunk_bytes * 8.0 / cardinality > 8.0) {
                    //     stats.very_sparse_chunks += 1;
                    //     stats.integers_in_very_sparse_chunks += cardinality;
                    // } else {
                    //     stats.sparse_chunks += 1;
                    //     stats.integers_in_sparse_chunks += cardinality;
                    // }

                    encode_sparse_chunk(begin, end, s, block, tmp);
                }

            } else {
                if (cardinality == chunk_universe) {
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

    write_uint<uint16_t>(chunks_header.size() / 3, out);
    auto ptr = reinterpret_cast<uint8_t const*>(chunks_header.data());
    out.insert(out.end(), ptr,
               ptr + chunks_header.size() * sizeof(chunks_header.front()));
    out.insert(out.end(), tmp.begin(), tmp.end());
}

struct s_index::builder1 {
    builder1(parameters const& params)
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

        m_offsets.push_back(0);

        for (size_t i = 2;  // first two values reserved for a singleton
                            // sequence containing the universe size
             i < input.size();) {
            uint32_t n = data[i];
            uint32_t universe = data[i + n];
            if (double(n) / universe > m_params.density) {
                encode_sequence(data + i + 1, n, block, stats, m_sequences);
                m_offsets.push_back(m_sequences.size());
                if (stats.sequences % 1000 == 0) {
                    std::cout << "processed " << stats.sequences << " sequences"
                              << std::endl;
                }
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

        m_offsets.pop_back();

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

};  // namespace sliced