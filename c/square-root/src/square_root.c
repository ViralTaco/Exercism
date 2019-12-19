#include "square_root.h"

#include <iso646.h>

inline unsigned square_root(const unsigned x) {
  if (x <= 1U)
    return x;
  
  unsigned beg = 1U, ans = 0U, end = x;
  
  while (beg <= end) {
    const unsigned mid = (beg + end) / 2U;
    const unsigned mid_squared = mid * mid;
    
    if (mid_squared == x) {
      return mid;
    } else if (mid_squared < x) { // rounded towards 0
      beg = mid + 1U;
      ans = mid;
    } else {
      end = mid - 1U;
    }
  }
  return ans;
}

inline unsigned squareRoot(const unsigned x) {
  return square_root(x);
}
