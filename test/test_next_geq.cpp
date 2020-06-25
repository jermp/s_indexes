#include <iostream>

#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "test_common.hpp"
#include "util.hpp"
#include "s_index.hpp"
#include "next_geq.hpp"

using namespace sliced;

void test(char const* binary_filename, parameters const& params) {
    s_index index;
    index.mmap(binary_filename);

    mm::file_source<uint32_t> input(params.collection_filename,
                                    mm::advice::sequential);
    uint32_t const* data = input.data();
    assert(data[0] == 1);
    std::cout << "universe size: " << index.universe() << std::endl;
    size_t k = 0;
    bool good = true;

    for (size_t i = 2; i < input.size();) {
        uint32_t n = data[i];
        uint32_t universe = data[i + n];
        if (pass(params, n, universe)) {
            auto sequence = index[k];
            uint32_t c = sequence.cardinality();

            if (c != n) {
                good = false;
                std::cout << "cardinality " << c << ": expected " << n
                          << std::endl;
            }

            uint32_t const* list = data + i + 1;

            /* run next_geq for all values in [0, universe] */
            for (size_t lower_bound = 0; lower_bound != universe + 1;
                 ++lower_bound) {
                auto it = std::lower_bound(list, list + n, lower_bound);
                uint32_t next_geq = sequence.next_geq(lower_bound);
                assert(next_geq >= lower_bound);
                if (next_geq != *it) {
                    good = false;
                    std::cout << "error at " << lower_bound << "/" << universe
                              << ": got " << next_geq
                              << " but expected next_geq(" << lower_bound
                              << ") = " << *it << std::endl;
                }
            }

            /* test some out-of-bound values */
            for (size_t lower_bound = universe + 1;
                 lower_bound != universe + 1000000 + 1; lower_bound += 10000) {
                uint32_t next_geq = sequence.next_geq(lower_bound);
                if (next_geq != constants::not_found) {
                    good = false;
                    std::cout << "error : got " << next_geq << " but expected "
                              << constants::not_found << std::endl;
                }
            }

            ++k;
            if (k % 1000 == 0) {
                std::cout << "checked " << k << " sequences" << std::endl;
            }
        }
        i += n + 1;
    }
    std::cout << "checked " << k << " sequences" << std::endl;
    if (good) {
        std::cout << "everything good" << std::endl;
    }
}

int main(int argc, char** argv) {
    TEST return 0;
}
