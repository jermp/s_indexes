#include <iostream>

#include "../external/essentials/include/essentials.hpp"
#include "s_index.hpp"

using namespace sliced;

void build(parameters const& params, char const* output_filename) {
    s_index::builder builder(params);
    s_index index;
    auto stats = builder.build(index);

    std::cout << "processed " << stats.sequences << " sequences, "
              << stats.integers << " integers" << std::endl;

    std::cout << "chunks: " << stats.chunks << std::endl;
    std::cout << "full chunks: " << stats.full_chunks << " ("
              << stats.integers_in_full_chunks * 100.0 / stats.integers
              << "% of ints)" << std::endl;
    std::cout << "empty chunks: " << stats.empty_chunks << " ("
              << stats.empty_chunks * 100.0 / stats.chunks << "% of chunks)"
              << std::endl;
    std::cout << "dense chunks: " << stats.dense_chunks << " ("
              << stats.integers_in_dense_chunks * 100.0 / stats.integers
              << "% of ints)" << std::endl;
    std::cout << "sparse chunks: " << stats.sparse_chunks << " ("
              << stats.integers_in_sparse_chunks * 100.0 / stats.integers
              << "% of ints)" << std::endl;

    std::cout << "blocks: " << stats.blocks << std::endl;
    std::cout << "full blocks: " << stats.full_blocks << " ("
              << stats.integers_in_full_blocks * 100.0 / stats.integers
              << "% of ints)" << std::endl;
    std::cout << "empty blocks: " << stats.empty_blocks << " ("
              << stats.empty_blocks * 100.0 / stats.blocks << "% of blocks)"
              << std::endl;
    std::cout << "dense blocks: " << stats.dense_blocks << " ("
              << stats.integers_in_dense_blocks * 100.0 / stats.integers
              << "% of ints)" << std::endl;
    std::cout << "sparse blocks: " << stats.sparse_blocks << " ("
              << stats.integers_in_sparse_blocks * 100.0 / stats.integers
              << "% of ints)" << std::endl;

    std::cout << double(stats.chunks_header_bits) / stats.integers
              << " [bpi] for chunks' headers" << std::endl;
    std::cout << double(stats.blocks_header_bits) / stats.integers
              << " [bpi] for blocks' headers" << std::endl;
    std::cout << double(stats.dense_chunks_bits) / stats.integers
              << " [bpi] for dense chunks" << std::endl;
    std::cout << double(stats.dense_blocks_bits) / stats.integers
              << " [bpi] for dense blocks" << std::endl;
    std::cout << double(stats.sparse_blocks_bits) / stats.integers
              << " [bpi] for sparse blocks" << std::endl;

    std::cout << "total bpi: " << double(stats.bits) / stats.integers
              << std::endl;

    if (output_filename) {
        essentials::print_size(index);
        std::cout << "saving data structure to disk..." << std::endl;
        essentials::save<s_index>(index, output_filename);
    }
}

int main(int argc, char** argv) {
    int mandatory = 3;
    if (argc < mandatory) {
        std::cout << argv[0]
                  << " <collection_filename> <density> [-o output_filename]"
                  << std::endl;
        return 1;
    }

    parameters params;
    params.collection_filename = argv[1];
    params.density = std::stod(argv[2]);

    char const* output_filename = nullptr;

    for (int i = mandatory; i != argc; ++i) {
        if (std::string(argv[i]) == "-o") {
            ++i;
            output_filename = argv[i];
        }
    }

    build(params, output_filename);

    return 0;
}
