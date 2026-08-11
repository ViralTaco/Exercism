/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "sieve.h"

#include <algorithm>
#include <iterator>

namespace sieve {

std::vector<int> primes(int limit)
{
  if (limit <= 1) return { /* empty vector */ };
  
  std::vector<int> number_set;    // B = { x ∈ N | 1 < x < limit }
  std::vector<int> non_prime_set; // A = { k ∈ B | 1 < k*x < limit}
  std::vector<int> prime_set;     // P-ish
  
  for (int i{2}; i < limit; ++i) {
    number_set.push_back(i);
    for (int j{2}; i * j < limit; ++j)
      non_prime_set.push_back(i * j);
  }
  
  // sort for std::unique
  std::sort(non_prime_set.begin(), non_prime_set.end());
  auto last = std::unique(non_prime_set.begin(), non_prime_set.end());

  // |B ∪ A| = P-ish
  std::set_difference(
    number_set.begin(), number_set.end()
  , non_prime_set.begin(), last
  , std::inserter(prime_set, prime_set.end())
  );
  
  // It was hard but I managed to make this as ineficient as possible
  // Still faster than Java.
  return prime_set;
}

} // namespace sieve
