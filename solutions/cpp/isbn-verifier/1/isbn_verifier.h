#pragma once /// Copyright 2026 viraltaco_ <https://anth.pro>
#ifndef VT_ISBN_VERIFIER_H
#define VT_ISBN_VERIFIER_H "com.virataco.isbn-verifier v" "1.0.0"

#include <string_view>

namespace isbn_verifier {
 inline namespace detail {
  using size_t = decltype (sizeof 0);
 } // namespace isbn_verifier::inline detail

  constexpr auto isbn_digit(const char c) noexcept -> int {
    switch (c) {
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'X': return 10;
    default:  return -1;
    }
  }

 constexpr auto is_valid(std::string_view isbn) noexcept -> bool {
   auto sum = 0;
   auto weight = 10;
   
   for (const char c : isbn) {
     if (c == '\0') break; // Ignore null terminator if passed via string literal
     if (c == '-')  continue;
     
     // Weight depleted -> more than 10 valid digits present
     if (weight == 0) return false;
     
     // 'X' is only valid as the check digit (weight 1)
     if (c == 'X' && weight != 1) return false;
     
     const int digit = isbn_digit(c);
     if (digit == -1) return false; // Invalid character
     
     sum += digit * weight;
     --weight;
   }
   
   // ISBN-10 must contain exactly 10 digits
   return weight == 0 && (sum % 11 == 0);
 }
} // namespace isbn_verifier

#endif // VT_ISBN_VERIFIER_H
