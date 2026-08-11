#pragma once /// Copyright (c) 2025 viraltaco_
#ifndef VT_PRIME_FACTORS_H_V1_1_0
#define VT_PRIME_FACTORS_H_V1_1_0 [[maybe_unused]] "v1.1.0"

#include <vector>

namespace prime_factors::inline v1_1_0 {

constexpr auto is_prime(auto x) noexcept -> bool {
  for (decltype (x) d = 2; d * d < x; ++d) {
    if (x % d == 0) return false;
  }
  return true;
}

namespace /*(filelocal)*/ { inline namespace detail {
 using natural = long long;
 using divisors = typename std::vector<natural>;
}} // namespace (filelocal)::inline detail

constexpr auto of(natural num) -> divisors {
  auto prime_factors = divisors{};
  
  // 2 is the only even prime so it gets its own loop.
  while (num >= 2 and num % 2 == 0) {
    num /= 2;
    prime_factors.push_back(2);
  }
  
  for (natural i = 3; num > 1; i += 2) {
    while (is_prime(i) and num % i == 0) {
      num /= i;
      prime_factors.push_back(i);
    }
  }
  
  return prime_factors;
}
} // namespace prime_factors::inline v1_1_0

#endif
