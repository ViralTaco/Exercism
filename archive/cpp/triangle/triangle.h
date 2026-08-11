#ifndef VT_TRIANGLE_H
#define VT_TRIANGLE_H

#define EXERCISM_RUN_ALL_TESTS true

#include <stdexcept>

namespace triangle {

enum class flavor: int { equilateral, isosceles, scalene };

template <typename Side> 
flavor kind(const Side a, const Side b, const Side c) {
  /**
   *  Triangle inequality:
   *  For any triangle, the sum of the lengths of any two sides
   *  must be GREATER THAN the length of the remaining side.
   */
  if (a + b <= c or b + c <= a or a + c <= b) {
    throw std::domain_error("Degenerate triangle or not a triangle.");
  } else if (a <= 0 or b <= 0 or c <= 0) {
    throw std::domain_error("A triangle must have sides with length > 0.");
  }

  if (a == b and b == c) {
    return flavor::equilateral;
  } else if (a == b or a == c or b == c) {
    return flavor::isosceles;
  }

  return flavor::scalene;
}

} // namespace triangle

#endif // VT_TRIANGLE_H (header guard)
