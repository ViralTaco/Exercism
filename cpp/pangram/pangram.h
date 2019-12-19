#ifndef VT_PANGRAM_H
#define VT_PANGRAM_H

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <string_view>

namespace pangram {
constexpr bool is_pangram(const std::string_view str) noexcept {
  bool seen[26] { false };

  for (const auto c: str) {
    if (c >= 'a' and c <= 'z') {
      seen[c - 'a'] = true;
    } else if (c >= 'A' and c <= 'Z') {
      seen[c - 'A'] = true;
    }
  }

  for (const bool b: seen) {
    if (not b) { return false; }
  }

  return true;
}
} // namespace pangram

#endif
