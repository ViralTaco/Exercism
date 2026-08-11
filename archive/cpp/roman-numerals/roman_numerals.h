#ifndef VT_ROMAN_NUMERAL_H
#define VT_ROMAN_NUMERAL_H
#define EXERCISM_RUN_ALL_TESTS

#include <string>

namespace roman_numerals {
struct numerals { int value; const char* letter; };

constexpr const numerals kMultiples[] {
  {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}
, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}
, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}
, {1, "I"}
};

std::string convert(int number);

} // namespace roman

#endif