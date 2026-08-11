#ifndef VT_BINARY_SEARCH_H
#define VT_BINARY_SEARCH_H

#define EXERCISM_RUN_ALL_TESTS true

#include <stdexcept>  // std::domain_error
#include <vector>     // obvious one
#include <cstddef>    // std::size_t

namespace binary_search {
  /**
   * This function take 2 arguments:
   * @param: `arr` a sorted array of integers
   * @param: `key` the integer to find in `arr`
   * It returns the position of `key` in `arr`
   * @return: size_t the position of `key` in `arr`
   * @throws: std::domain_error if `key` isn't in `arr`
   */
  std::size_t find(const std::vector<int>& arr, int key);
  
}  // namespace binary_search

#endif // VT_BINARY_SEARCH_H
