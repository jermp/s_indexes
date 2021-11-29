#include <iostream>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "select.hpp"

using namespace sliced;

void perf_select(char const* binary_filename,
                 uint64_t num_queries_per_sequence) {
    s_index index;
    index.mmap(binary_filename);

    uint64_t total_queries = index.size() * num_queries_per_sequence;
    std::vector<uint32_t> queries;
    queries.reserve(total_queries);

    std::cout << "reading queries..." << std::endl;
    for (uint32_t i = 0; i != total_queries; ++i) {
        uint32_t q;
        int x = scanf("%d", &q);
        if (x == EOF) break;
        queries.push_back(q);
    }
    std::cout << "DONE" << std::endl;

    size_t total = 0;
    std::cout << "performing " << queries.size() << " select queries..."
              << std::endl;
    essentials::timer_type t;
    static const int runs = 3 + 1;
    for (int run = 0; run != runs; ++run) {
        uint64_t q = 0;
        uint32_t value = 0;
        t.start();
        for (uint32_t i = 0; i != index.size(); ++i) {
            auto sequence = index[i];
            for (uint32_t j = 0; j != num_queries_per_sequence; ++j) {
                sequence.select(queries[q++], value);
                total += value;
            }
        }
        t.stop();
    }
    std::cout << total << std::endl;
    t.discard_first();
    double avg = t.average();
    std::cout << "Mean per run: " << avg << " [musec]\n";
    std::cout << "Mean per query: " << avg / total_queries << " [musec]";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int mandatory = 3;
    if (argc < mandatory) {
        std::cout << argv[0]
                  << " index_filename num_queries_per_sequence < queries"
                  << std::endl;
        return 1;
    }

    char const* binary_filename = argv[1];
    uint64_t num_queries_per_sequence = std::stoull(argv[2]);
    perf_select(binary_filename, num_queries_per_sequence);

    return 0;
}
