#include "pangram.h"

//constexpr bool pangram::is_pangram(const std::string_view str) noexcept {
//  bool seen[26] { false };
//  
//  for (const auto c: str) {
//    if (c >= 'a' and c <= 'z') {
//      seen[c - 'a'] = true;
//    } else if (c >= 'A' and c <= 'Z') {
//      seen[c - 'A'] = true;
//    }
//  }
//
//  for (const bool b: seen) {
//    if (not b) { return false; }
//  }
//
//  return true;
//}

