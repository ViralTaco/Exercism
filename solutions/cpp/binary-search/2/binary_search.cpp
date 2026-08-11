#include "binary_search.h"
#include <stdexcept> // std::domain_error
#include <numeric>   // std::midpoint

namespace binary_search {
std::size_t find(std::vector<int> const& arr, const int key) { // O(log N)
  int lhs = 0, mid = 0, rhs = static_cast<int> (arr.size()) - 1;
  
  for (; lhs <= rhs; mid = std::midpoint(lhs, rhs)) {
    // We already checked bounds; `operator []` is best.
    const int mid_v = arr[mid];
    
    if (mid_v == key)
      return mid;
    
    if (mid_v < key)
      lhs = mid + 1;
    else
      rhs = mid - 1;
  }
  
  throw std::domain_error("No value matching key in array.");
}
} // namespace binary_search
