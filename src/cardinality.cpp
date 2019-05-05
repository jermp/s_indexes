#include <iostream>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"

using namespace sliced;

void perf_cardinality(char const* binary_filename) {
    s_index index;
    index.mmap(binary_filename);

    size_t total = 0;
    essentials::timer_type t;
    static const int runs = 10 + 1;
    for (int run = 0; run != runs; ++run) {
        t.start();
        for (size_t i = 0; i != index.size(); ++i) {
            auto sequence = index[i];
            total += sequence.cardinality();
        }
        t.stop();
    }
    std::cout << total << std::endl;
    t.discard_first();
    double avg = t.average();
    std::cout << "Mean per run: " << avg << " [musec]\n";
    std::cout << "Mean per query: " << avg / index.size() * 1000 << " [ns]";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int mandatory = 2;
    if (argc < mandatory) {
        std::cout << argv[0] << " <index_filename>" << std::endl;
        return 1;
    }

    perf_cardinality(argv[1]);
    return 0;
}
