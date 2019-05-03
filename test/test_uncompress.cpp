#include <iostream>

#include "immintrin.h"

#include "../external/essentials/include/essentials.hpp"
#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "uncompress.hpp"

using namespace sliced;

uint32_t decode_bitmap_and_reset(uint64_t* bitmap, size_t size_in_64bit_words,
                                 uint32_t* out) {
    uint32_t size = 0;
    uint32_t base = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
        while (w != 0) {
            uint64_t t = w & (~w + 1);
            int r = __builtin_ctzll(w);
            out[size++] = r + base;
            w ^= t;
        }
        bitmap[i] = 0;
        base += 64;
    }
    return size;
}

void test_uncompress(char const* binary_filename,
                     char const* collection_filename, double density) {
    s_index index;
    index.mmap(binary_filename);

    mm::file_source<uint32_t> input(collection_filename,
                                    mm::advice::sequential);
    uint32_t const* data = input.data();

    assert(data[0] == 1);
    uint32_t universe = data[1];
    std::cout << "universe size: " << universe << std::endl;

    size_t size_in_64bit_words = essentials::words_for(52000000);
    std::vector<uint64_t> bitmap(size_in_64bit_words, 0);
    std::vector<uint32_t> out(universe);
    size_t k = 0;

    for (size_t i = 2; i < input.size();) {
        uint32_t n = data[i];
        uint32_t universe = data[i + n];
        if (double(n) / universe > density) {
            auto sequence = index[k];
            size_t decoded = sequence.uncompress(bitmap.data());
            decoded = decode_bitmap_and_reset(bitmap.data(),
                                              size_in_64bit_words, out.data());

            if (decoded != n) {
                std::cout << "decoded " << decoded << " integers: expected "
                          << n << std::endl;
            }

            uint32_t const* ptr = data + i + 1;
            for (size_t j = 0; j != n; ++j) {
                uint32_t expected = *ptr++;
                if (expected != out[j]) {
                    std::cout << "error at " << j << "/" << n << ": expected "
                              << expected << " but got " << out[j] << std::endl;
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
    std::cout << "everything good" << std::endl;
}

int main(int argc, char** argv) {
    int mandatory = 4;
    if (argc < mandatory) {
        std::cout << argv[0]
                  << " <index_filename> <collection_filename> <density>"
                  << std::endl;
        return 1;
    }

    char const* index_filename = argv[1];
    char const* collection_filename = argv[2];
    double density = std::stod(argv[3]);

    test_uncompress(index_filename, collection_filename, density);

    return 0;
}
