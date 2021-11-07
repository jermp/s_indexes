#pragma once

#include <vector>
#include <sstream>
#include <algorithm>

namespace sliced {

namespace testing {
typedef std::vector<uint32_t> query_type;

bool read_query_and_remove_duplicates(query_type& query,
                                      std::istream& is = std::cin) {
    query.clear();
    std::string line;
    if (!std::getline(is, line)) return false;
    std::istringstream iline(line);
    uint32_t index;
    while (iline >> index) query.push_back(index);
    std::sort(query.begin(), query.end());
    query.erase(std::unique(query.begin(), query.end()), query.end());
    return true;
}
}  // namespace testing

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