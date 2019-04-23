#include <iostream>

#include "immintrin.h"

#include "../external/essentials/include/essentials.hpp"
#include "../external/mm_file/include/mm_file/mm_file.hpp"

#include "util.hpp"
#include "s_index.hpp"
#include "uncompress.hpp"
#include "tables.hpp"

using namespace sliced;

uint32_t decode_bitmap_and_reset(uint64_t* bitmap, size_t size_in_64bit_words,
                                 uint32_t* out) {
    __m256i base_vec = _mm256_set1_epi32(-1);
    __m256i inc_vec = _mm256_set1_epi32(64);
    __m256i add8 = _mm256_set1_epi32(8);

    size_t decoded = 0;
    for (size_t i = 0; i != size_in_64bit_words; ++i) {
        uint64_t w = bitmap[i];
        if (w == 0) {
            base_vec = _mm256_add_epi32(base_vec, inc_vec);
        } else {
            for (int k = 0; k < 4; ++k) {  // process 2 bytes of data at a time
                uint8_t byte1 = (uint8_t)w;
                uint8_t byte2 = (uint8_t)(w >> 8);
                w >>= 16;
                __m256i vec1 = _mm256_load_si256(
                    (const __m256i*)tables::dictionary[byte1]);
                __m256i vec2 = _mm256_load_si256(
                    (const __m256i*)tables::dictionary[byte2]);
                uint8_t advance1 = tables::size[byte1];
                uint8_t advance2 = tables::size[byte2];
                vec1 = _mm256_add_epi32(base_vec, vec1);
                base_vec = _mm256_add_epi32(base_vec, add8);
                vec2 = _mm256_add_epi32(base_vec, vec2);
                base_vec = _mm256_add_epi32(base_vec, add8);
                _mm256_storeu_si256((__m256i*)(out + decoded), vec1);
                decoded += advance1;
                _mm256_storeu_si256((__m256i*)(out + decoded), vec2);
                decoded += advance2;
            }
            bitmap[i] = 0;
        }
    }

    return decoded;
}

void check_uncompress(char const* binary_filename,
                      char const* collection_filename, double density) {
    s_index index;
    essentials::load(index, binary_filename);
    essentials::print_size(index);

    mm::file_source<uint32_t> input(collection_filename,
                                    mm::advice::sequential);
    uint32_t const* data = input.data();

    assert(data[0] == 1);
    uint32_t universe = data[1];
    std::cout << "universe size: " << universe << std::endl;

    size_t size_in_64bit_words = essentials::words_for(universe);
    std::cout << "size_in_64bit_words " << size_in_64bit_words << std::endl;
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

    check_uncompress(index_filename, collection_filename, density);

    return 0;
}
