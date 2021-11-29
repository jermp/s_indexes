#include <iostream>
#include <algorithm>
#include <sstream>

#include "util.hpp"
#include "s_index.hpp"
#include "enumerator.hpp"
#include "test_common.hpp"
#include "union_many.hpp"

using namespace sliced;
using namespace sliced::testing;

typedef std::vector<uint32_t> query_type;

std::vector<uint32_t> pairwise_union(std::vector<uint32_t> const& l,
                                     std::vector<uint32_t> const& r) {
    auto it_l = l.begin();
    auto it_r = r.begin();
    std::vector<uint32_t> out;
    while (true) {
        if (it_l == l.end()) {
            std::copy(it_r, r.end(), std::back_inserter(out));
            break;
        }
        if (it_r == r.end()) {
            std::copy(it_l, l.end(), std::back_inserter(out));
            break;
        }
        if (*it_l < *it_r) {
            out.push_back(*it_l);
            ++it_l;
        } else if (*it_r < *it_l) {
            out.push_back(*it_r);
            ++it_r;
        } else {
            out.push_back(*it_l);
            ++it_l;
            ++it_r;
        }
    }
    return out;
}

std::vector<uint32_t> union_many(s_index const& index,
                                 query_type const& query) {
    assert(query.size() >= 2);
    std::vector<std::vector<uint32_t>> sequences(query.size());
    for (uint32_t i = 0; i != query.size(); ++i) {
        auto sequence = index[query[i]];
        enumerator e;
        e.init(sequence, index.universe());
        sequences[i].reserve(sequence.cardinality());
        while (e.has_next()) {
            sequences[i].push_back(e.value());
            e.next();
        }
        assert(sequences[i].size() == sequence.cardinality());
        assert(std::is_sorted(sequences[i].begin(), sequences[i].end()));
    }

    std::vector<uint32_t> result;
    for (uint32_t i = 0; i != sequences.size(); ++i) {
        result = pairwise_union(result, sequences[i]);
    }

    return result;
}

void test(char const* binary_filename, std::vector<query_type> const& queries) {
    s_index index;
    index.mmap(binary_filename);

    uint64_t universe = index.universe();
    std::vector<uint32_t> out(universe);
    bool good = true;

    std::vector<s_sequence> sequences;
    uint64_t num_queries = 0;
    for (auto const& q : queries) {
        if (q.size() < 2) continue;
        sequences.clear();
        auto expected = union_many(index, q);
        for (uint32_t i = 0; i != q.size(); ++i) {
            sequences.push_back(index[q[i]]);
        }
        size_t size = union_many(sequences, out.data());
        std::cout << "union has size " << size << std::endl;
        if (expected.size() != size) {
            good = false;
            std::cout << "union has size " << size << " but expected "
                      << expected.size() << std::endl;
        }

        for (size_t i = 0; i != size; ++i) {
            if (expected[i] != out[i]) {
                good = false;
                std::cout << "error at " << i << "/" << size << ": expected "
                          << expected[i] << " but got " << out[i] << std::endl;
            }
        }
        ++num_queries;
    }
    std::cout << "tested " << num_queries << " queries" << std::endl;
    if (good) std::cout << "everything good" << std::endl;
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

    std::cout << "reading queries..." << std::endl;
    std::vector<query_type> queries;
    queries.reserve(num_queries);
    query_type q;
    uint64_t i = 0;
    while (i != num_queries and testing::read_query_and_remove_duplicates(q)) {
        assert(!q.empty());
        queries.push_back(q);
        ++i;
    }

    std::cout << "running test..." << std::endl;
    test(binary_filename, queries);

    return 0;
}
