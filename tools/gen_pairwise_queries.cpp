#include <iostream>

#include "../external/essentials/include/essentials.hpp"

void generate(uint32_t num_queries, uint32_t num_sequences) {
    essentials::uniform_int_rng<uint32_t> rng(0, num_sequences - 1);
    for (size_t i = 0; i != num_queries; ++i) {
        std::cout << rng.gen() << "\t" << rng.gen() << "\n";
    }
}

int main(int argc, char** argv) {
    int mandatory = 3;
    if (argc < mandatory) {
        std::cout << argv[0] << " num_queries num_sequences" << std::endl;
        return 1;
    }

    generate(std::atoi(argv[1]), std::atoi(argv[2]));
    return 0;
}
