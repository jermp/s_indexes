#pragma once

namespace sliced {

namespace constants {

static const uint32_t chunk_size = uint32_t(1) << 16;
static const uint32_t block_size = uint32_t(1) << 8;

static const uint64_t chunk_size_in_64bit_words = chunk_size / 64;
static const uint64_t block_size_in_64bit_words = block_size / 64;

static const uint64_t chunk_sparseness_threshold = chunk_size / 2;
static const uint64_t block_sparseness_threshold = block_size / 8;

static const uint32_t associativity = 32;

static const uint32_t not_found = uint32_t(-1);

}  // namespace constants
}  // namespace sliced