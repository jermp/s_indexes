#include <iostream>

#include <sys/time.h>
#include <time.h>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "intersection.hpp"

using namespace sliced;

inline double get_time_usecs() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((double)tv.tv_sec) * 1000000 + ((double)tv.tv_usec);
}

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

    // essentials::timer_type t;
    double total_usecs = 0.0;
    static const int runs = 10;
    for (int run = 0; run != runs; ++run) {
        // t.start();
        double start = get_time_usecs();
        for (auto const& q : queries) {
            total += pairwise_intersection(index[q.i], index[q.j], out.data());
        }
        // t.stop();
        double end = get_time_usecs();
        double elapsed = end - start;
        total_usecs += elapsed;
    }

    std::cout << total << std::endl;

    // t.discard_min_max();
    // double elapsed = t.average();

    std::cout << "Elapsed time: " << total_usecs / 1000000 << " [sec]\n";
    std::cout << "Mean per run: " << total_usecs / runs << " [musec]\n";
    std::cout << "Mean per query: " << total_usecs / runs / queries.size()
              << " [musec]";
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
