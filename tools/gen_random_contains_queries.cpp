#include <iostream>
#include <algorithm>

#include "../external/essentials/include/essentials.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "decode.hpp"

using namespace sliced;

void generate(char const* binary_filename, uint32_t num_queries) {
    s_index index;
    index.mmap(binary_filename);

    std::vector<query> queries;
    queries.reserve(index.size() * num_queries);
    std::vector<uint32_t> out(index.universe());

    for (size_t i = 0; i != index.size(); ++i) {
        auto sequence = index[i];
        size_t decoded = sequence.decode(out.data());
        query q;
        essentials::uniform_int_rng<uint32_t> rng(0, decoded - 1);
        for (uint32_t k = 0; k != num_queries; ++k) {
            q.i = i;
            q.j = out[rng.gen()];
            queries.push_back(q);
        }
    }

    // std::random_shuffle(queries.begin(), queries.end());
    for (auto q : queries) {
        std::cout << q.i << "\t" << q.j << "\n";
    }
}

int main(int argc, char** argv) {
    int mandatory = 3;
    if (argc < mandatory) {
        std::cout << argv[0] << " index_filename num_queries_per_list"
                  << std::endl;
        return 1;
    }

    generate(argv[1], std::atoi(argv[2]));
    return 0;
}
