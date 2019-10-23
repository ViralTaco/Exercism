#pragma once

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <stdexcept>

namespace triangle {

enum Triangle { equilateral, isosceles, scalene };

template <typename T>
static const Triangle kind(const T side_a, const T side_b, const T side_c) noexcept(false) {
  // Triangle inequality:
  // For any triangle, the sum of the lengths of any two sides must be
  // greater than or equal to the length of the remaining side.
  if (side_a >= side_b + side_c or side_b >= side_a + side_c or side_c >= side_a + side_b) {
    throw std::domain_error("Degenerate triangle or not a triangle.");
  } else if (side_a <= 0 or side_b <= 0 or side_c <= 0) {
    throw std::domain_error("A triangle cannot have sides of length <= 0.");
  }

  if (side_a == side_b and side_b == side_c) {
    return triangle::equilateral;
  } else if (side_a == side_b or side_a == side_c or side_b == side_c) {
    return triangle::isosceles;
  }

  return triangle::scalene;
}

} // namespace triangle
