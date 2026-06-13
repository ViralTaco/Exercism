#include "rotational_cipher.h"

auto rotational_cipher::v0_0_1::rotate(std::string text, std::size_t key) -> std::string {
  const auto rot = [k=key] (char c) {
    if (std::isalpha(c)) {
      const char kBasis = std::islower(c) ? 'a' : 'A';
      const char kIndex = c - kBasis;
      return static_cast<char>(kBasis + (k + kIndex) % 26);
    }
    return c;
  };
  std::transform(text.begin(), text.end(), text.begin(), rot);
  return text;
}
