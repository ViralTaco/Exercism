#include "armstrong_numbers.h"

#include <cmath>   // std::pow
#include <numeric> // std::accumulate
#include <string>  // std::to_string

namespace armstrong_numbers {
[[nodiscard]] auto is_armstrong_number(const int n) -> bool {
  const auto num = std::to_string(n);
  return n < 10
      or n == std::accumulate(num.crbegin(), num.crend(), 0,
        [k = num.size()] (int i, auto c) {
          return i + std::pow(c - '0', k);
      });
}
}  // namespace armstrong_numbers
