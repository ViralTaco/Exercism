/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "isogram_fast.hpp"

#include <cctype>

[[nodiscard]] bool isogram::is_isogram(const std::string& str) {
  if (str.empty()) {
    return true;
  }
  
  bool arr[26]{};
  for (const auto c: str) {
    if (::isalpha(c) == 0) { // if not letter: skip
      continue;
    } 
    
    const int pos{ ::tolower(c) - 'a' };
    if (not arr[ pos ]) {
      arr[ pos ] = true;
    } else {
      return false;
    }
  }
  
  return true;
}
