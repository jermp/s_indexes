#pragma once

#include "immintrin.h"

#include "configuration.hpp"
#include "tables.hpp"

#define chunk_pair(l, r) (3 * (l) + (r))

namespace sliced {

size_t intersect_sparse_sparse(uint8_t const* l, uint8_t const* r,
                               uint32_t* out) {
    // todo
}

size_t intersect_dense_sparse(uint8_t const* l, uint8_t const* r,
                              uint32_t* out) {
    // todo
}

size_t intersect_full_sparse(uint8_t const* l, uint8_t const* r,
                             uint32_t* out) {
    // decode sparse
}

size_t intersect_full_dense(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    // decode dense
}

size_t intersect_dense_dense(uint8_t const* l, uint8_t const* r,
                             uint32_t* out) {
    // bitwise and
}

size_t intersect_full_full(uint8_t const* l, uint8_t const* r, uint32_t* out) {
    // nothing
}

size_t pairwise_intersection(s_sequence const& l, s_sequence const& r,
                             uint32_t* out) {
    iterator it_l = l.begin();
    iterator it_r = r.begin();
    size_t size = 0;

    while (it_l.has_next() and it_r.has_next()) {
        uint16_t id_l = it_l.id();
        uint16_t id_r = it_r.id();

        if (id_l == id_r) {
            uint32_t n = 0;
            switch (chunk_pair(it_l.type(), it_r.type())) {
                case chunk_pair(type::sparse, type::sparse):
                    n = intersect_sparse_sparse(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::sparse, type::dense):
                    n = intersect_dense_sparse(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::sparse, type::full):
                    n = intersect_full_sparse(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::dense, type::sparse):
                    n = intersect_dense_sparse(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::dense):
                    n = intersect_dense_dense(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::dense, type::full):
                    n = intersect_full_dense(it_r.data, it_l.data, out);
                    break;
                case chunk_pair(type::full, type::sparse):
                    n = intersect_full_sparse(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::dense):
                    n = intersect_full_dense(it_l.data, it_r.data, out);
                    break;
                case chunk_pair(type::full, type::full):
                    n = intersect_full_full(it_l.data, it_r.data, out);
                    break;
                default:
                    assert(false);
                    __builtin_unreachable();
            }

            uint32_t base = id_l << 16;
            for (size_t i = 0; i != n; ++i) {
                out[i] += base;
            }

            out += n;
            size += n;
            it_l.next();
            it_r.next();

        } else if (id_l < id_r) {
            it_l.advance(id_r);
        } else {
            it_r.advance(id_l);
        }
    }

    return size;
}

}  // namespace sliced