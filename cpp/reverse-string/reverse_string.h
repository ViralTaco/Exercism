/*
 * Copyright (c) 2019 ViralTaco
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_REVERSE_STRING_H
#define VT_REVERSE_STRING_H

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <algorithm>
#include <string>

namespace reverse_string {
std::string reverse_string(std::string str)
{
  std::reverse(str.begin(), str.end());
  return str;
}

} // namespace reverse_string

#endif
