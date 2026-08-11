#ifndef VIRALTACO_EXERCISM_ISOGRAM_H
#define VIRALTACO_EXERCISM_ISOGRAM_H "0.2.0"
/// copyright 2021,2022,2025,2026 viraltaco_ <https://opensource.org/licenses/MIT>
#include <string_view>  // std::string_view

namespace isogram {
 inline namespace detail {
  using size_t = decltype (sizeof 0);
  
  template <class T> constexpr auto in_range(T a, T z, T v)
  -> bool { return a <= v and v <= z; }

  constexpr auto lower = [] (auto c) { return in_range('a', 'z', c); };
  constexpr auto upper = [] (auto c) { return in_range('A', 'Z', c); };
  constexpr auto alpha = [] (auto c) { return lower(c) or upper(c); };
 } // namespace ::isogram::inline detail

 constexpr auto is_isogram(const std::string_view str) noexcept -> bool {
   auto seen = 0u;
     for (auto c: str) {
       if (not alpha(c)) continue;
       const auto bit = 1u << size_t(upper(c) ? c - 'A' : c - 'a');
      if (seen & bit) return false;
      seen |= bit;
    }
    return true;
 }
} // namespace ::isogram
#endif
