/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_SAY_H
#define VT_SAY_H
#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <string>

namespace say {
static constexpr unsigned long long kTrillion{ 1000000000000ULL };

static constexpr unsigned long long kMultList[]{
  1000000000ULL, 1000000ULL, 1000ULL, 100ULL
};

static const std::string kMultStr[]{
  "billion", "million", "thousand", "hundred"
};

static const std::string kSmallMult[]{
  "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

static const std::string kSmallNums[]{
  "zero", "one", "two", "three", "four", "five", "six"
, "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen"
, "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
};

std::string in_english(unsigned long long num);
} // namespace say

#endif
