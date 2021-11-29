#include <iostream>

#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "test_common.hpp"
#include "util.hpp"
#include "s_index.hpp"
#include "enumerator.hpp"

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

    enumerator e;

    for (size_t i = 2; i < input.size();) {
        uint32_t n = data[i];
        uint32_t universe = data[i + n];
        if (pass(params, n, universe)) {
            auto sequence = index[k];
            e.init(sequence, index.universe());

            uint32_t const* ptr = data + i + 1;
            for (size_t j = 0; j != n; ++j, e.next()) {
                uint32_t expected = *ptr++;
                uint32_t got = e.value();
                if (expected != got) {
                    good = false;
                    std::cout << "error at " << j << "/" << n << ": expected "
                              << expected << " but got " << got << std::endl;
                }
            }

            ++k;
            if (k % 1000 == 0) {
                std::cout << "decoded " << k << " sequences" << std::endl;
            }
        }
        i += n + 1;
    }
    std::cout << "decoded " << k << " sequences" << std::endl;
    if (good) std::cout << "everything good" << std::endl;
}

int main(int argc, char** argv) {
    TEST return 0;
}
