/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_SERIES_H
#define VT_SERIES_H
#define EXERCISM_RUN_ALL_TESTS

#include <string>
#include <vector>

namespace series {
std::vector<int> digits(const std::string& num_list);

std::vector< std::vector<int> > 
slice(const std::string& num_list, const std::size_t series_length);
} // namespace series

#endif
