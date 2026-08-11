#ifndef VT_ROMAN_NUMERAL_H
#define VT_ROMAN_NUMERAL_H "com.viraltaco.roman-numerals v" "2.0.0"

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS true
#endif // EXERCISM_RUN_ALL_TESTS

#include <string>

namespace roman_numerals {
struct numerals { const int value; char const* letter; };

[[nodiscard]] auto convert(int number) noexcept -> std::string;

} // namespace roman

#endif