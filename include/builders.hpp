#pragma once

#include <iostream>
#include <cassert>

#include "util.hpp"

namespace sliced {

template <typename W>
void set_bit(size_t position, std::vector<W>& bits) {
    assert(position < bits.size() * sizeof(W) * 8);
    size_t w = position / (sizeof(W) * 8);
    size_t o = position % (sizeof(W) * 8);
    bits[w] |= W(1) << o;
}

template <typename T>
void write_uint(T val, std::vector<uint8_t>& out) {
    auto ptr = reinterpret_cast<uint8_t const*>(&val);
    out.insert(out.end(), ptr, ptr + sizeof(T));
}

void write_bits(uint32_t const* begin, size_t n, size_t bits, uint32_t base,
                std::vector<uint8_t>& out) {
    std::vector<uint64_t> bitmap(bits / 64, 0);
    for (uint32_t i = 0; i != n; ++i, ++begin) {
        uint32_t val = *begin - base;
        set_bit(val, bitmap);
    }
    auto ptr = reinterpret_cast<uint8_t const*>(bitmap.data());
    out.insert(out.end(), ptr, ptr + bitmap.size() * sizeof(bitmap.front()));
}

void write_header(uint32_t block_id, size_t offset, std::vector<uint8_t>& out,
                  uint32_t type) {
    assert(block_id < 256);
    size_t b = block_id / 4;
    size_t o = block_id % 4;
    out[offset + b] |= type << (o * 2);
}

void encode_block(std::vector<uint32_t>& block, uint32_t& block_id,
                  size_t header_offset, statistics& stats,
                  std::vector<uint8_t>& out, bool write) {
    stats.blocks += 1;
    assert(block.size() <= constants::block_size);

    if (block.empty()) {
        stats.empty_blocks += 1;
    } else {
        if (block.size() == constants::block_size) {
            stats.full_blocks += 1;
            stats.integers_in_full_blocks += constants::block_size;

            if (write) {
                write_header(block_id, header_offset, out, type::full);
            }

        } else if (block.size() >= constants::block_sparseness_threshold - 1) {
            stats.dense_blocks += 1;
            stats.dense_blocks_bits += constants::block_size;
            stats.integers_in_dense_blocks += block.size();
            if (write) {
                write_header(block_id, header_offset, out, type::dense);
                write_bits(block.data(), block.size(), constants::block_size, 0,
                           out);
            }
        } else {
            assert(block.size() <= constants::block_sparseness_threshold - 2);
            stats.sparse_blocks += 1;
            stats.integers_in_sparse_blocks += block.size();
            stats.sparse_blocks_bits += 8 * (block.size() + 1);

            if (write) {
                write_header(block_id, header_offset, out, type::sparse);
                write_uint<uint8_t>(block.size(), out);
                for (auto pos : block) {
                    write_uint<uint8_t>(pos, out);
                }
            }
        }

        block.clear();
    }

    block_id += 1;
}

uint32_t chunk_cardinality(uint32_t const* begin, uint32_t const* end,
                           uint32_t left, uint32_t right) {
    uint32_t c = 0;
    while (*begin < right and begin != end) {
        assert(*begin >= left);
        assert(*begin - left < constants::chunk_size);
        ++begin;
        ++c;
    }
    return c;
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

    uint32_t left = 0;
    uint32_t right = constants::chunk_size;
    for (uint32_t i = 0; i != chunks; ++i) {
        // std::cout << "[" << left << ", " << right << ")" << std::endl;

        if (*begin < right) {
            uint32_t cardinality = chunk_cardinality(begin, end, left, right);

            // actual chunk universe
            // uint32_t chunk_universe = *(begin - 1) - base + 1;

            // std::cout << "actual universe " << *(begin - 1) - base + 1
            //           << std::endl;

            uint32_t chunk_universe = constants::chunk_size;
            uint32_t dense_chunk_bytes = bytes_for(chunk_universe);
            assert(dense_chunk_bytes * 8 <= constants::chunk_size);
            assert(cardinality <= constants::chunk_size);
            assert(chunk_universe <= constants::chunk_size);
            assert(cardinality <= chunk_universe);

            // std::cout << "cardinality " << cardinality <<
            // std::endl;

            chunks_header.push_back(i);

            if (cardinality < constants::chunk_sparseness_threshold) {
                statistics sparse_chunk_stats;
                bool write = false;  // first ride computes chunks' bits
                size_t header_offset = tmp.size();
                uint32_t block_id = 0;
                uint32_t base = left;
                while (*begin < right and begin != end) {
                    uint32_t val = *begin - base;
                    if (val >= constants::block_size) {
                        encode_block(block, block_id, header_offset,
                                     sparse_chunk_stats, tmp, write);
                        base += constants::block_size;
                    } else {
                        assert(val < constants::block_size);
                        block.push_back(val);
                        assert(block.size() <= constants::block_size);
                        ++begin;
                    }
                }
                encode_block(block, block_id, header_offset, sparse_chunk_stats,
                             tmp, write);

                uint64_t sparse_chunk_bytes =
                    (2 * blocks_in_chunk +  // header bits
                     sparse_chunk_stats.dense_blocks_bits +
                     sparse_chunk_stats.sparse_blocks_bits) /
                    8;

                if (sparse_chunk_bytes >= dense_chunk_bytes) {
                    stats.dense_chunks += 1;
                    stats.dense_chunks_bits += dense_chunk_bytes * 8;
                    stats.integers_in_dense_chunks += cardinality;
                    chunks_header.push_back(type::dense);
                    chunks_header.push_back(constants::chunk_size / 8);
                    write_bits(begin - cardinality, cardinality,
                               constants::chunk_size, left, tmp);
                } else {
                    stats.sparse_chunks += 1;
                    stats.integers_in_sparse_chunks += cardinality;

                    stats.blocks += blocks_in_chunk;
                    assert(sparse_chunk_stats.blocks <= blocks_in_chunk);
                    stats.empty_blocks +=
                        blocks_in_chunk - sparse_chunk_stats.blocks;

                    stats.full_blocks += sparse_chunk_stats.full_blocks;
                    stats.dense_blocks += sparse_chunk_stats.dense_blocks;
                    stats.sparse_blocks += sparse_chunk_stats.sparse_blocks;
                    stats.empty_blocks += sparse_chunk_stats.empty_blocks;

                    stats.integers_in_full_blocks +=
                        sparse_chunk_stats.integers_in_full_blocks;
                    stats.integers_in_dense_blocks +=
                        sparse_chunk_stats.integers_in_dense_blocks;
                    stats.integers_in_sparse_blocks +=
                        sparse_chunk_stats.integers_in_sparse_blocks;

                    stats.dense_blocks_bits +=
                        sparse_chunk_stats.dense_blocks_bits;
                    stats.sparse_blocks_bits +=
                        sparse_chunk_stats.sparse_blocks_bits;

                    chunks_header.push_back(type::sparse);
                    chunks_header.push_back(sparse_chunk_bytes);

                    // write space for headers
                    size_t header_offset = tmp.size();
                    uint64_t empty[8] = {0};
                    auto ptr = reinterpret_cast<uint8_t const*>(empty);
                    tmp.insert(tmp.end(), ptr, ptr + 8 * sizeof(uint64_t));

                    begin -= cardinality;
                    write = true;
                    uint32_t block_id = 0;
                    base = left;
                    while (*begin < right and begin != end) {
                        uint32_t val = *begin - base;
                        if (val >= constants::block_size) {
                            encode_block(block, block_id, header_offset,
                                         sparse_chunk_stats, tmp, write);
                            base += constants::block_size;
                        } else {
                            assert(val < constants::block_size);
                            block.push_back(val);
                            assert(block.size() <= constants::block_size);
                            ++begin;
                        }
                    }
                    encode_block(block, block_id, header_offset,
                                 sparse_chunk_stats, tmp, write);
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
                    write_bits(begin, cardinality, constants::chunk_size, left,
                               tmp);
                }
                begin += cardinality;
            }

        } else {
            stats.empty_chunks += 1;
        }

        left = right;
        right += constants::chunk_size;
    }

    write_uint<uint16_t>(chunks_header.size() / 3, out);
    auto ptr = reinterpret_cast<uint8_t const*>(chunks_header.data());
    out.insert(out.end(), ptr,
               ptr + chunks_header.size() * sizeof(chunks_header.front()));
    out.insert(out.end(), tmp.begin(), tmp.end());
}

};  // namespace sliced