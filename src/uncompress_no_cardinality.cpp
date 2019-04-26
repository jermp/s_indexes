#include <iostream>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "uncompress.hpp"

using namespace sliced;

void uncompress_no_cardinality(char const* binary_filename) {
    s_index index;
    // essentials::load(index, binary_filename);
    // essentials::print_size(index);
    index.mmap(binary_filename);

    const uint32_t universe = 52000000;
    std::vector<uint64_t> out(essentials::words_for(universe), 0);

    essentials::timer_type t;
    t.start();
    for (size_t i = 0; i != index.size(); ++i) {
        auto sequence = index[i];
        sequence.uncompress_no_cardinality(out.data());
        essentials::do_not_optimize_away(out.front());
    }
    t.stop();

    std::cout << "decoded " << index.size() << " sequences" << std::endl;
    double elapsed = t.average();
    std::cout << "Elapsed time: " << elapsed / 1000000 << " [sec]\n";
    std::cout << "Mean per sequence: " << elapsed / index.size() << " [musec]"
              << std::endl;
}

int main(int argc, char** argv) {
    int mandatory = 2;
    if (argc < mandatory) {
        std::cout << argv[0] << " <index_filename>" << std::endl;
        return 1;
    }

    uncompress_no_cardinality(argv[1]);
    return 0;
}
