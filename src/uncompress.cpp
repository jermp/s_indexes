#include <iostream>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "uncompress.hpp"

using namespace sliced;

void uncompress(char const* binary_filename) {
    s_index index;
    index.mmap(binary_filename);

    const uint32_t universe = 52000000;
    std::vector<uint64_t> out(essentials::words_for(universe), 0);
    uint64_t integers = 0;

    essentials::timer_type t;
    t.start();
    for (size_t i = 0; i != index.size(); ++i) {
        auto sequence = index[i];
        size_t decoded = sequence.uncompress(out.data());
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

    uncompress(argv[1]);
    return 0;
}
