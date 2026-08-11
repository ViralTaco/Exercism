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

template <typename Integral> 
using Matrix = typename std::vector< std::vector<Integral> >;

Matrix<int> generate_rows(const int);

} // namespace pascals_triangle

#endif
