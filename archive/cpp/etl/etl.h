/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_ETL_H
#define VT_ETL_H

#define EXERCISM_RUN_ALL_TESTS

#include <map>
#include <vector>

namespace etl {
std::map<char, int> transform(const std::map<int, std::vector<char>>& old);
}


#endif
