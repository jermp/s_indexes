#include <iostream>

#include "../external/essentials/include/essentials.hpp"
#include "s_index.hpp"

using namespace sliced;

void build(parameters const& params, char const* output_filename) {
    s_index::builder builder(params);
    s_index index;
    auto stats = builder.build(index);
    stats.print();
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
