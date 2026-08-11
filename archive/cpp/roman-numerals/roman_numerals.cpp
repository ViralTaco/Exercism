#include "roman_numerals.h"

[[nodiscard]] std::string roman_numerals::convert(int number) noexcept(false)
{
  std::string result{};
  for (const auto& n: roman_numerals::kMultiples) {
    while (number >= n.value) {
      result += n.letter;
      number -= n.value;
    }
  }
  return result;
}
