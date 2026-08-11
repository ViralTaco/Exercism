// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ nth_prime.cpp:                                       ┃
// ┃ Copyright (c) 2019 - 2020 viraltaco_                 ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#include "nth_prime.h"
#include <stdexcept> // std::domain_error
#include <cmath>     // std::sqrt

/// P: n is odd!
/// R: true if n is not a composite integer.
auto nth_prime::is_prime(const u64 n) noexcept -> bool {
  const u64 lim = 1.0f + std::sqrt(static_cast<float> (n));
  for (u64 d = 3ul; d < lim; d += 2ul) {
    if (n % d == 0ul) { return false; }
  }
  return true;
}

auto nth_prime::nth(u64 n) -> u64 {
  if (n == 0ul) {
    throw std::domain_error("No.");
  } else if (n <= Wheel::size) {
    return Wheel::get(n);
  } else {
    n -= Wheel::size - 2ul;
    for (u64 x = Wheel::last; ; x += 2ul) {
      n -= is_prime(x);
      if (not (n > 1)) { return x; }
    }
  }
}
