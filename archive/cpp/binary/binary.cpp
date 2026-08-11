#include "binary.h"

#include <algorithm>

namespace binary {
int convert(const std::string binary_num) {

  if (std::any_of(binary_num.begin(), binary_num.end()
  , [] (char c) noexcept { return c > '1' or c < '0'; }
  )) {
    return 0;
  }
  
  return std::stoi(binary_num, 0, 2);
}
}  // namespace binary
