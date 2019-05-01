#pragma once

namespace sliced {

namespace constants {

static const uint32_t chunk_size = uint32_t(1) << 16;
static const uint32_t block_size = uint32_t(1) << 8;

static const uint64_t chunk_size_in_64bit_words = chunk_size / 64;
static const uint64_t block_size_in_64bit_words = block_size / 64;

static const uint64_t chunk_sparseness_threshold = chunk_size / 2;
static const uint64_t block_sparseness_threshold = block_size / 8;

static const uint64_t C = (uint64_t(1) << 3) + (uint64_t(1) << 11) +
                          (uint64_t(1) << 19) + (uint64_t(1) << 27) +
                          (uint64_t(1) << 35) + (uint64_t(1) << 43) +
                          (uint64_t(1) << 51) + (uint64_t(1) << 59);

}  // namespace constants
}  // namespace sliced