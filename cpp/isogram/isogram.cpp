/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "isogram.h"

#include <algorithm>
#include <cctype>

[[nodiscard]] bool isogram::is_isogram(std::string str) {
  auto end { // remove non-letters
    std::remove_if(str.begin(), str.end()
    , [] (char c) { return ::isalpha(c) == 0; }
    )
  };

  // Because taking the address of a standard library
  // function is unspecified behaviour: wrap it in lambda
  std::transform(str.begin(), end, str.begin()
  , [] (char c) { return ::tolower(c); }
  );
  std::sort(str.begin(), end);
  
  return end == std::unique(str.begin(), end);
}
