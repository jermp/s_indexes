#pragma once

namespace sliced {

#define TEST                                                                  \
    int mandatory = 3;                                                        \
    if (argc < mandatory) {                                                   \
        std::cout                                                             \
            << argv[0]                                                        \
            << " index_filename collection_filename [--density d] [--size s]" \
            << std::endl;                                                     \
        return 1;                                                             \
    }                                                                         \
                                                                              \
    char const* index_filename = argv[1];                                     \
    parameters params;                                                        \
    params.collection_filename = argv[2];                                     \
                                                                              \
    for (int i = mandatory; i != argc; ++i) {                                 \
        if (std::string(argv[i]) == "--density") {                            \
            ++i;                                                              \
            params.density = std::stod(argv[i]);                              \
        } else if (std::string(argv[i]) == "--size") {                        \
            ++i;                                                              \
            params.size = std::atoi(argv[i]);                                 \
        }                                                                     \
    }                                                                         \
                                                                              \
    test(index_filename, params);

}  // namespace sliced