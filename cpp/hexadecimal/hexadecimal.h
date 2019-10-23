#pragma once
#define EXERCISM_RUN_ALL_TESTS

#include <string>

#include <cstring>
#include <cmath>

namespace hexadecimal {
size_t convert(const std::string& hex)
{
  size_t len{hex.length()};
  if (len == 0)
    return 0;
  
  size_t temp{0};
  char c{0};
  
  for (size_t i{1}; i <= len; ++i) {
    c = hex[len - i];
    
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
    
    temp += c * static_cast<size_t>(std::pow(16, i - 1));
  }
  return temp;
}

} // namespace hexadecimal
