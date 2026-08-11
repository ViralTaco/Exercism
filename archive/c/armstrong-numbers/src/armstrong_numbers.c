/* clang -std=c11 -Ofast -Weverything -Wextra -Wall -Wpedantic
 */

#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int num) {
  if (num < 10)
    return num >= 0;
    
  int exponent = (int)(log10f(num)) + 1;
  for (int i = num; i > 0; i /= 10)
    num -= pow(i % 10, exponent);
  
  return num == 0;
  
}
