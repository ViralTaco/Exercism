#ifndef VT_LEAP_H
#define VT_LEAP_H "com.viraltaco.leap v" "2.0.0"

namespace leap::inline v2_0_0 {
constexpr auto is_leap_year(const unsigned y) noexcept -> bool {
  // cf: Implementing Fast Calendar Algorithms: Speeding Date - Cassio Neri - C++ on Sea 2023
  // https://youtu.be/J9KijLyP-yg?t=1321
  const auto d = (y % 100 != 0) ? 4 : 16;
  return (y & (d - 1)) == 0;
}
} // namespace leap

#endif // VT_LEAP_H
