#ifndef VT_LEAP_H
#define VT_LEAP_H

namespace leap {
constexpr auto is_leap_year(const unsigned y) noexcept -> bool {
  if (y % 100 != 0) {
    return y % 4 == 0;
  } else {
    return y % 400 == 0;
  }
}
} // namespace leap

#endif // VT_LEAP_H
