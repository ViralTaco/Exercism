/*
 * Copyright (c) 2019 viraltaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_LUHN_H
#define VT_LUHN_H

#define EXERCISM_RUN_ALL_TESTS 1

#include <string_view>
#include <cctype>

namespace luhn {

constexpr bool is_odd(const int x) noexcept { 
  return x & 1; 
}

constexpr int reduce(const int num) noexcept { 
  return (num > 4) ? (2 * num) - 9 : (2 * num); 
}

constexpr int ctoi(const int ascii_num) noexcept { 
  return ascii_num - '0'; 
}

constexpr bool valid(std::string_view sin) noexcept {
  const int kLength = static_cast<int>(sin.length()) - 1;
  if (kLength < 1) {
    return false;
  }
  
  int digits_count = 0;
  int sum = 0;
  
  for (int i = kLength; i >= 0; --i) {
    const int c = sin[i];
    
    if (std::isdigit(c)) {
      sum += (is_odd(digits_count)) ? reduce(ctoi(c)) : ctoi(c);
      ++digits_count;
    } else if (not std::isspace(c)) {
      return false;
    }
  }
  return (sum == 0) ? digits_count > 1 : sum % 10 == 0;
}

} // namespace luhn

#endif
