#include <iostream>
#include <algorithm>

#include "util.hpp"
#include "s_index.hpp"
#include "intersection.hpp"

using namespace sliced;

void test_intersection(char const* binary_filename,
                       std::vector<query> const& queries) {
    s_index index;
    index.mmap(binary_filename);

    std::vector<uint32_t> out(52000000);
    std::vector<uint32_t> i(52000000);
    std::vector<uint32_t> j(52000000);
    std::vector<uint32_t> expected(52000000);

    for (auto const& q : queries) {
        size_t i_size = index[q.i].decode(i.data());
        size_t j_size = index[q.j].decode(j.data());
        auto it =
            std::set_intersection(i.begin(), i.begin() + i_size, j.begin(),
                                  j.begin() + j_size, expected.begin());
        size_t expected_size = it - expected.begin();
        size_t size = pairwise_intersection(index[q.i], index[q.j], out.data());

        if (expected_size != size) {
            std::cout << "intersection has size " << size << " but expected "
                      << expected_size << std::endl;
        }

        for (size_t i = 0; i != size; ++i) {
            if (expected[i] != out[i]) {
                std::cout << "error at " << i << "/" << size << ": expected "
                          << expected[i] << " but got " << out[i] << std::endl;
            }
        }
    }
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

    test_intersection(binary_filename, queries);

    return 0;
}
