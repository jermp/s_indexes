#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "building_util.hpp"

#include "../external/essentials/include/essentials.hpp"

void gen(uint32_t num_lists, uint32_t min_length, uint32_t max_length,
         uint32_t universe, char const* output_filename) {
    using namespace sliced;
    std::ofstream out(std::string(output_filename),
                      std::ios_base::binary | std::ios_base::out);
    // header: singleton list containing the universe
    write_uint(uint32_t(1), out);
    write_uint(universe, out);
    essentials::uniform_int_rng<uint32_t> length(min_length, max_length);
    essentials::uniform_int_rng<uint32_t> element(0, universe);
    std::vector<uint32_t> list;
    list.reserve(max_length);
    for (uint32_t i = 0; i != num_lists; ++i) {
        list.clear();
        uint32_t n = length.gen();
        for (uint32_t k = 0; k != n; ++k) {
            list.push_back(element.gen());
        }
        std::sort(list.begin(), list.end());
        auto it = std::unique(list.begin(), list.end());
        n = std::distance(list.begin(), it);
        write_uint(n, out);
        char const* begin = reinterpret_cast<char const*>(list.data());
        out.write(begin, n * sizeof(uint32_t));
    }
    out.close();
}

int main(int argc, char** argv) {
    int mandatory = 6;
    if (argc < mandatory) {
        std::cout << argv[0]
                  << " num_lists min_length max_length universe output_filename"
                  << std::endl;
        return 1;
    }

    uint32_t num_lists = std::atoi(argv[1]);
    uint32_t min_length = std::atoi(argv[2]);
    uint32_t max_length = std::atoi(argv[3]);
    uint32_t universe = std::atoi(argv[4]);
    char const* output_filename = argv[5];

    gen(num_lists, min_length, max_length, universe, output_filename);

    return 0;
}
