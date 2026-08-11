/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "etl.h"
#include <cctype>

std::map<char, int> etl::transform(const std::map<int, std::vector<char>>& old)
{
  std::map<char, int> result;
  
  for (const auto& pair: old)
    for (const auto c: pair.second)
      if (std::isalpha(c))
        result.insert({std::tolower(c), pair.first});
        
  return result;
}
