/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "prime_factors.h"
#include <cmath>

bool prime_factors::is_prime(int x) noexcept {
  for (int d = 2; d < (int) sqrt(x); ++d) {
    if (x % d == 0) {
      return false;
    }
  }
  return true;
}

std::vector<int> prime_factors::of(int num) {
  std::vector<int> factors;
  
  // 2 is the only even prime so it gets its own loop. 
  while (num % 2 == 0 && num >= 2) {
    num /= 2;
    factors.push_back(2);
  }
  
  for (int i = 3; num > 1; i += 2) {
    if (prime_factors::is_prime(i)) {
      while (num % i == 0) {
        num /= i;
        factors.push_back(i);
      }
    }
  }
  return factors;
}
