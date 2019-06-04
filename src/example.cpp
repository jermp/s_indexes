#include <iostream>

#include "../external/essentials/include/essentials.hpp"
#include "builder.hpp"
#include "s_sequence.hpp"
#include "select.hpp"
#include "decode.hpp"

using namespace sliced;

int main(int argc, char** argv) {
    int mandatory = 1;
    char const* output_filename = nullptr;

    for (int i = mandatory; i != argc; ++i) {
        if (std::string(argv[i]) == "-o") {
            ++i;
            output_filename = argv[i];
        } else if (std::string(argv[i]) == "-h") {
            std::cout << argv[0] << " -o output_filename < input" << std::endl;
            return 1;
        } else {
            std::cout << "unknown option '" << argv[i] << "'" << std::endl;
            return 1;
        }
    }

    std::vector<uint32_t> input;

    {  // read input from std::in
        uint32_t n, x;
        std::cin >> n;
        input.reserve(n);
        for (uint32_t i = 0; i != n; ++i) {
            std::cin >> x;
            input.push_back(x);
        }
    }

    // build the sequence and print statistics
    s_sequence::builder builder;
    auto stats = builder.build(input.data(), input.size());
    stats.print();

    mm::file_source<uint8_t> mm_file;
    uint8_t const* data = nullptr;

    if (output_filename) {  // if an output file is specified, then serialize
        essentials::print_size(builder);
        essentials::save<s_sequence::builder>(builder, output_filename);

        // mmap
        int advice = mm::advice::normal;  // can be also random and sequential
        mm_file.open(output_filename, advice);

        // skip first 8 bytes storing the number of written bytes
        data = mm_file.data() + 8;

    } else {  // otherwise work directly in memory
        data = builder.data();
    }

    // initialize a s_sequence from data, regardless the source
    s_sequence ss(data);

    uint32_t size = ss.size();

    // decode whole list to an output buffer
    std::vector<uint32_t> out(size);
    ss.decode(out.data());
    // check written values
    uint32_t value = 0;
    for (uint32_t i = 0; i != size; ++i) {
        if (input[i] != out[i]) {
            std::cout << "got " << out[i] << " but expected " << input[i]
                      << std::endl;
            return 1;
        }

        ss.select(i, value);  // select i-th element
        if (value != out[i]) {
            std::cout << "got " << value << " but expected " << out[i]
                      << std::endl;
            return 1;
        }
    }

    return 0;
}
