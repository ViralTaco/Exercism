#include "all_your_base.h"
#include <cmath>

using uint = unsigned int;

std::vector<uint> all_your_base::convert(const uint base_in
, const std::vector<uint>& number
, const uint base_out )
{
  const std::size_t size{ number.size() };
  
  if (size == 0 || base_in < 2 || base_out < 2 || number.front() == 0)
    return { /* empty */ };
    
  std::size_t exponent{ size - 1 };
  std::vector<uint> result;
  uint64_t accumulator{ 0ULL };

  for (uint i{0}; i < size; ++i, --exponent) {
    if (number[i] >= base_in) return { /* empty */ };
    
    accumulator += number[i] * std::pow(base_in, exponent);
  }

  while (accumulator > 0) {
    result.push_back(accumulator % base_out);
    accumulator /= base_out;
  }
  
  return { result.rbegin(), result.rend() };
}
