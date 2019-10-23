/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "nth_prime.h"
#include <cmath>
#include <stdexcept>

// Great. This is gonna be fun.
static constexpr std::size_t kPadding{0};
static constexpr std::size_t kPrimeArraySize{59};
static constexpr std::size_t kSmallPrimes[kPrimeArraySize]{ 
  kPadding, 2, 3, 5, 7, 11, 13, 17
, 19, 23, 29, 31, 37, 41, 43, 47, 53
, 59, 61, 67, 71, 73, 79, 83, 89, 97
, 101, 103, 107, 109, 113, 127, 131
, 137, 139, 149, 151, 157, 163, 167
, 173, 179, 181, 191, 193, 197, 199
, 211, 223, 227, 229, 233, 239, 241
, 251, 257, 263, 269, 271
};

template <typename T> bool prime::is_prime(T x)
{
  for (T d{2}; d <= static_cast<T>(sqrt(x)); ++d) 
    if (x % d == 0) 
      return false;
  return true;
}

std::size_t prime::nth(std::size_t n)
{
  if (n == 0) {
    throw std::domain_error("No.");
  } else if (n < kPrimeArraySize) {
    return kSmallPrimes[n];
  }

  std::size_t result{3}; // prime number 2
  for (; n > 1; result += 2)
    if (result & 1 && is_prime(result))
      --n;

  // result is bicremented one too many times because for loops.
  return result - 2;
}
