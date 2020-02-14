#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "building_util.hpp"

#include "../external/essentials/include/essentials.hpp"

enum event_code { skip = 0, include_all = 1, include_some = 2 };

struct event {
    int code;
    float prob;
};

int gen_event(std::vector<event> const& events, float p) {
    assert(p >= 0 and p <= 1.0);
    float cumulative = events[0].prob;
    size_t i = 0;
    while (cumulative < p) {
        ++i;
        cumulative += events[i].prob;
    }
    assert(i < events.size());
    return events[i].code;
};

void gen(uint32_t num_lists, uint32_t universe, char const* output_filename,
         bool binary) {
    using namespace sliced;

    std::ofstream out;
    if (binary) {
        out.open(std::string(output_filename),
                 std::ios_base::binary | std::ios_base::out);
    } else {
        out.open(std::string(output_filename));
    }

    if (!out.is_open()) {
        std::cout << "error in opening file" << std::endl;
        return;
    }

    if (binary) {
        // header: singleton list containing the universe
        write_uint(uint32_t(1), out);
        write_uint(universe, out);
    }

    essentials::uniform_int_rng<uint32_t> length(10, constants::chunk_size / 4);
    typedef essentials::uniform_int_rng<uint32_t> random_int;
    random_int* element = nullptr;

    std::vector<uint32_t> list;
    list.reserve(universe);

    std::vector<event> events(3);
    events[0] = {event_code::skip, 0.3};
    events[1] = {event_code::include_all, 0.2};
    events[2] = {event_code::include_some, 0.5};

    for (uint32_t i = 0; i != num_lists; ++i) {
        list.clear();

        slice s = {0, constants::chunk_size};
        while (s.left < universe) {
            float p = float(rand()) / RAND_MAX;
            int code = gen_event(events, p);
            uint32_t n = 0;
            uint32_t end = std::min<uint32_t>(s.right, universe);
            switch (code) {
                case event_code::skip:
                    break;
                case event_code::include_all:
                    for (uint32_t k = s.left; k != end; ++k) {
                        list.push_back(k);
                    }
                    break;
                case event_code::include_some:
                    element = new random_int(s.left, end);
                    n = length.gen();
                    for (uint32_t k = 0; k != n; ++k) {
                        list.push_back(element->gen());
                    }
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }
            s.left = s.right;
            s.right += constants::chunk_size;
        }

        std::sort(list.begin(), list.end());
        auto end = std::unique(list.begin(), list.end());
        uint32_t n = std::distance(list.begin(), end);

        if (binary) {
            write_uint(n, out);
            char const* begin = reinterpret_cast<char const*>(list.data());
            out.write(begin, n * sizeof(uint32_t));
        } else {
            out << n << "\n";
            for (auto x : list) {
                out << x << "\n";
            }
        }
    }
    out.close();
}

int main(int argc, char** argv) {
    int mandatory = 4;
    if (argc < mandatory) {
        std::cout << argv[0] << " num_lists universe output_filename --binary"
                  << std::endl;
        return 1;
    }

    uint32_t num_lists = std::atoi(argv[1]);
    uint32_t universe = std::atoi(argv[2]);
    char const* output_filename = argv[3];
    bool binary = false;

    for (int i = mandatory; i != argc; ++i) {
        if (std::string(argv[i]) == "--binary") {
            binary = true;
        }
    }

    gen(num_lists, universe, output_filename, binary);

    return 0;
}
