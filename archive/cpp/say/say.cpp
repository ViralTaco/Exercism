/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "say.h"

std::string say::in_english(unsigned long long num)
{
  if (num > say::kTrillion - 1ULL)
    throw std::domain_error("The number must be between 0 and 1E12 - 1");
  
  auto val{0ULL};
  std::string result{};

  if (num > 99ULL) {
    for (int i{0}; i < 4; ++i) {
      val = num / kMultList[i];
      if ((val) != 0) {
        result += say::in_english(val) + " " + kMultStr[i] + " ";
        num -= kMultList[i] * val;
      }
    }
  }
  
  if (num > 20ULL) {
    auto temp{ num / 10 };
    result += kSmallMult[temp - 2] + "-"; // kSmallMult[0] -> "twenty"
    num -= 10 * temp;
  }
  
  if (num > 0 || result.empty())
    result += kSmallNums[num];
  
  if (!result.empty() && result.back() == ' ')
    result.pop_back();
    
  return result;
}
