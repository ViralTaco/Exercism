#include "roman_numerals.h"

[[nodiscard]] auto roman_numerals::convert(int number) noexcept -> std::string {
  static constexpr numerals kMultiples[] {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}
  , { 100, "C"}, { 90, "XC"}, { 50, "L"}, { 40, "XL"}
  , {  10, "X"}, {  9, "IX"}, {  5, "V"}, {  4, "IV"}
  , {   1, "I"}
  };

  auto result = std::string{};
  for (auto const& n: kMultiples) {
    while (number >= n.value) {
      result += n.letter;
      number -= n.value;
    }
  }
  return result;
}
