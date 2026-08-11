#include "largest_series_product.h"
#include <iso646.h> // and, or, not, etc,...
#include <string.h> // strnlen
#include <ctype.h>

[[nodiscard]]
int_least64_t largest_series_product(char const* digits, const size_t span) {
  enum { INVALID_SPAN = -1 , NULLPTR_STRING = -1 };
  #define vt_digit_at(INDEX) (digits[(INDEX)] - '0')
  #define vt_not_digit(CHAR) ('0' > (CHAR) or (CHAR) > '9')
  
  if (digits == nullptr) { return NULLPTR_STRING; }
  
  const size_t kLength = strlen(digits);
  if (span > kLength) { return INVALID_SPAN; }
  
  int zeroes = 0;
  int_least64_t tmp = 1LL;
  for (int i = 0; i != (int)span; ++i) {
    if (vt_not_digit(digits[i])) { return INVALID_SPAN; }
    
    const int k = vt_digit_at(i);
    if (k == 0) {
      ++zeroes;
    } else {
      tmp *= k;
    }
  }
  // If the window doesn't contain zeros, update max
  int_least64_t max = (zeroes == 0) * tmp;
  
  for (int i = span; i != (int)kLength; ++i) {
    if (vt_not_digit(digits[i])) { return INVALID_SPAN; }
    
    const int in  = vt_digit_at(i)
            , out = vt_digit_at(i - span)
            ;
    
    // update zero count:
    zeroes += (in == 0) - (out == 0);
    if (zeroes == 0) { // If no zeros, update product
      if (out != 0) {
        tmp = (tmp / out) * in;
      } else { // Recalculate product if zero is leaving the window
        tmp = 1;
        for (int j = i - span + 1; j <= i; ++j) {
          tmp *= vt_digit_at(j);
        }
      }
    } else { // If zeros are present, set product to 0
      tmp = 0;
    }
    
    max = (max > tmp) ? max : tmp;
  }
  
  return max;
  
  #undef vt_digit_at
  #undef vt_not_digit
}
