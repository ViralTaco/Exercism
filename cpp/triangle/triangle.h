#ifndef VT_TRIANGLE_H
#define VT_TRIANGLE_H

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <stdexcept>

namespace triangle {

enum class flavor: int { equilateral, isosceles, scalene };

template <typename T> flavor
kind(const T a, const T b, const T side_c) {
  /**
   *  Triangle inequality:
   *  For any triangle, the sum of the lengths of any two sides must be
   *  greater than or equal to the length of the remaining side.
   */
  if (a >= b + side_c
  or  b >= a + side_c
  or  side_c >= a + b) {
    throw std::domain_error("Degenerate triangle or not a triangle.");
  } else if (a <= 0 or b <= 0 or side_c <= 0) {
    throw std::domain_error("A triangle cannot have sides of length <= 0.");
  }

  if (a == b and b == side_c) {
    return flavor::equilateral;
  } else if (a == b or a == side_c or b == side_c) {
    return flavor::isosceles;
  }

  return flavor::scalene;
}

} // namespace triangle

#endif // VT_TRIANGLE_G (header guard)
