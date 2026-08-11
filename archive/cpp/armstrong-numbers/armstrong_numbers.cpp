#include "armstrong_numbers.h"
#include <cmath>
#include <string>

[[nodiscard]] bool armstrong_numbers::is_armstrong_number(const int n) {
  if (n <= 10) {
    return true;
  }
  
  const std::string num_str{ std::to_string(n) };
  // using int since lenght of an number can't be longer than INT_MAX
  const int len{ static_cast<int>(num_str.length()) }; 
  
  int total{};
  
  for (const auto c: num_str) {
    // lazilly casting to and from float...
    total += ::pow(c - '0', len);
  }
  
  return total == n;
}

