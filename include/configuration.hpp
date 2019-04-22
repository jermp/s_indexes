#pragma once

namespace sliced {

namespace constants {

static const uint32_t chunk_size = uint32_t(1) << 16;
static const uint32_t block_size = uint32_t(1) << 8;

static const uint64_t chunk_sparseness_threshold = chunk_size / 2;
static const uint64_t block_sparseness_threshold = block_size / 8;

}  // namespace constants
}  // namespace sliced