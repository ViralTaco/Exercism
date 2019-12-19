#include "hexadecimal.h"

#include <cctype> // std::isalpha(), std::tolower()
#include <cmath>  // std::pow()

namespace hexadecimal {
  long convert(const std::string_view hex) noexcept {
    const long kLen = hex.length();
    if (kLen == 0)
      return 0;

    long decimal = 0L;
    unsigned char c = '\0';

    for (int i = 1; i <= kLen; ++i) {
      c = hex[kLen - i];

      if (c <= '9' && c >= '0') {
        c -= '0';
      } else if (std::isalpha(c)) {
        c = std::tolower(c);
        if (c <= 'f') {
          c = 10 + (c - 'a');
        } else { // out of range.
          return 0;
        }
      }

      decimal += c * std::pow(16, i - 1);
    }
    return decimal;
  }
}  // namespace hexadecimal
