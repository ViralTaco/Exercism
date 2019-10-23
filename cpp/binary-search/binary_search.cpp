#include "binary_search.h"

namespace binary_search {
std::size_t find(const std::vector<int>& arr, int key) { // O(log N)
  int lhs = 0, mid = 0, rhs = arr.size() - 1;
  
  for (; lhs <= rhs; mid = lhs + (rhs - lhs) / 2) {
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
