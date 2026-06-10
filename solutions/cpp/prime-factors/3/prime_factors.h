#pragma once /// Copyright (c) 2025, 2026 viraltaco_
#ifndef VT_PRIME_FACTORS_H
#define VT_PRIME_FACTORS_H "com.viraltaco.prime-factors v" "2.0.0"

#include <bit> // std::countr_zero
#include <type_traits> // std::make_unsigned
#include <vector>

namespace prime_factors::inline v2_0_0 {
inline namespace detail { using NaturalType = long long; }
constexpr auto of(NaturalType num) noexcept -> std::vector<NaturalType> {
  if (num < 2) [[unlikely]] {
    return {};
  } else if (not (num ^ 2) or (num & 1 and num < 9)) [[unlikely]] { // 2,3,5,7
    return { num };
  }
  
  auto prime_factors = std::vector<NaturalType>{};
  prime_factors.reserve(8); // Max 15 UNIQUE prime factors in a signed 64 bit int
  
  // 2 is the only even prime so it gets its own loop.
  if (not (num & 1)) { // Is even
    using UnsignedNatural = typename std::make_unsigned_t<NaturalType>;
    const auto kZeroes = std::countr_zero(static_cast<UnsignedNatural> (num));
    prime_factors.insert(prime_factors.end(), kZeroes, 2);
    num >>= kZeroes;
  }

  while (num % 3 == 0) {
    prime_factors.push_back(3);
    num /= 3;
  }
  
  for (NaturalType i = 5; i * i <= num; i += 6) {
    while (num % i == 0) {
      prime_factors.push_back(i);
      num /= i;
    }
    const auto j = i + 2;
    while (num % j == 0) {
      prime_factors.push_back(j);
      num /= j;
    }
  }

  if (num > 2) [[likely]] prime_factors.push_back(num);
  return prime_factors;
}
} // namespace prime_factors

#endif
