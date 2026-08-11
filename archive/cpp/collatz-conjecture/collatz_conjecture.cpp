#include "collatz_conjecture.h"
#include <stdexcept>

[[nodiscard]] int collatz_conjecture::steps(int n) {
  if (n < 1) {
    throw std::domain_error("n must be bigger than 0");
  }
  
  int step{ 0 };
  while (n != 1) {
    ++step;
    
    if (n & 1) { // n is odd
      n = 3 * n + 1;
    } else {
      n /= 2;
    }
  }
  return step;
}
