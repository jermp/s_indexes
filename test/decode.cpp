#include <iostream>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "decode.hpp"

using namespace sliced;

void decode(char const* binary_filename) {
    s_index index;
    essentials::load(index, binary_filename);
    essentials::print_size(index);

    const uint32_t universe = 25000000;
    std::vector<uint32_t> out(universe);
    uint64_t integers = 0;

    essentials::timer_type t;
    t.start();
    for (size_t i = 0; i != index.size(); ++i) {
        auto sequence = index[i];
        size_t decoded = sequence.decode(out.data());
        integers += decoded;
    }
    t.stop();

    std::cout << "decoded " << index.size() << " sequences" << std::endl;
    std::cout << "decoded " << integers << " integers" << std::endl;

    double elapsed = t.average();
    std::cout << "Elapsed time: " << elapsed / 1000000 << " [sec]\n";
    std::cout << "Mean per sequence: " << elapsed / index.size()
              << " [musec]\n";
    std::cout << "Mean per integer: " << elapsed / integers * 1000 << " [ns]";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int mandatory = 2;
    if (argc < mandatory) {
        std::cout << argv[0] << " <index_filename>" << std::endl;
        return 1;
    }

    decode(argv[1]);
    return 0;
}
