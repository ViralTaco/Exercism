#ifndef VIRALTACO_EXERCISM_ISOGRAM_H
#define VIRALTACO_EXERCISM_ISOGRAM_H "1.1.0"
/// copyright 2021,2022,2025,2026 viraltaco_ <https://opensource.org/licenses/MIT>
#include <string_view> // std::string_view
#include <cstdint>     // std::uint_least32_t;

namespace isogram {
 inline namespace detail {
   using u32 = std::uint_least32_t;
   
   template <class T> constexpr auto in_range(T a, T z, T v) -> bool {
     return a <= v and v <= z;
   }
   
   constexpr auto lower = [] (auto c) { return in_range('a', 'z', c); };
   constexpr auto upper = [] (auto c) { return in_range('A', 'Z', c); };
   constexpr auto alpha = [] (auto c) { return lower(c) or upper(c); };
   constexpr auto index = [] (auto c) -> u32 {
     return static_cast<u32> (upper(c) ? c - 'A' : c - 'a');
   };
 } // namespace ::isogram::detail

 constexpr auto is_isogram(const std::string_view str) noexcept -> bool {
   auto seen = u32{};
   for (auto c: str) {
     if (not alpha(c)) { // Not letter, skip!
       continue;
     }

     const auto bit = u32{1u} << index(c);
     if (seen & bit) { // Not isogram, return false!
       return false;
     } else {
       seen |= bit;
     }
   }
   return true;
 }
} // namespace ::isogram
#endif
