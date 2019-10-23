/*
 * Copyright (c) 2019 viraltaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_PASCAL_TRIANGLE_H
#define VT_PASCAL_TRIANGLE_H

#define EXERCISM_RUN_ALL_TESTS 1

#include <vector>

namespace pascals_triangle {

template <class Tn> using matrix_t = typename std::vector< std::vector<Tn> >;

matrix_t<int> generate_rows(unsigned int rows);

} // namespace pascals_triangle

#endif