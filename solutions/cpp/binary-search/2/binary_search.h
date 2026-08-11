#ifndef VT_BINARY_SEARCH_H
#define VT_BINARY_SEARCH_H "com.viraltaco.binary-search v" "2.0.0"

#ifndef EXERCISM_RUN_ALL_TESTS
# define EXERCISM_RUN_ALL_TESTS true
#endif //ndef EXERCISM_RUN_ALL_TESTS

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
  std::size_t find(std::vector<int> const& arr, const int key);
  
}  // namespace binary_search

#endif // VT_BINARY_SEARCH_H
