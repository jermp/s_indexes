#include <iostream>

#include <sys/time.h>
#include <time.h>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "intersection.hpp"

using namespace sliced;

void intersection(char const* binary_filename,
                  std::vector<query> const& queries) {
    s_index index;
    essentials::load(index, binary_filename);
    essentials::print_size(index);

    const uint32_t universe = 52000000;
    std::vector<uint32_t> out(universe);
    size_t total = 0;

    std::cout << "performing " << queries.size() << " pairwise-intersections..."
              << std::endl;

    essentials::timer_type t;
    static const int runs = 10;
    for (int run = 0; run != runs; ++run) {
        t.start();
        for (auto const& q : queries) {
            total += pairwise_intersection(index[q.i], index[q.j], out.data());
        }
        t.stop();
    }

    std::cout << total << std::endl;

    double avg = t.average();
    std::cout << "Mean per run: " << avg << " [musec]\n";
    std::cout << "Mean per query: " << avg / queries.size() << " [musec]";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int mandatory = 3;
    if (argc < mandatory) {
        std::cout << argv[0] << " index_filename num_queries < queries"
                  << std::endl;
        return 1;
    }

    char const* binary_filename = argv[1];
    uint64_t num_queries = std::stoull(argv[2]);
    std::vector<query> queries;
    queries.reserve(num_queries);

    std::cout << "reading queries..." << std::endl;
    for (uint32_t i = 0; i != num_queries; ++i) {
        query q;
        int x = scanf("%d", &q.i);
        int y = scanf("%d", &q.j);
        if (x == EOF or y == EOF) {
            break;
        }
        queries.push_back(q);
    }
    std::cout << "DONE" << std::endl;

    intersection(binary_filename, queries);

    return 0;
}
