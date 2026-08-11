#ifndef VT_HEXADECIMAL_H
#define VT_HEXADECIMAL_H "4.0.2"
/// copyright 2019-2022 viraltaco_ <https://opensource.org/licenses/MIT>

#include <string_view>
#include <array>

namespace hexadecimal {
 constexpr auto convert(const std::string_view hex) noexcept {
   enum: char { invalid = '\xFF' };

   constexpr auto map = [] {
     auto self = std::array<char, 256>{};
     self.fill(invalid);
     for (auto c = '0'; c <= '9'; ++c) self[c] = c - '0';
     for (auto c = 'a'; c <= 'f'; ++c) self[c] = c - 'a' + 0xA;
     for (auto c = 'A'; c <= 'F'; ++c) self[c] = c - 'A' + 0xA;
     return self;
   }();
 
   auto sum = 0u;
   for (unsigned char c: hex) {
     if (auto x = map[c]; x != invalid) {
       sum = sum << 4 | x; // sum * 16 + x
     } else if (c != '\0') {
       return 0u;
     }
   }
   return sum;
 }
} // namespace hexadecimal
#endif // VT_HEXADECIMAL_H
