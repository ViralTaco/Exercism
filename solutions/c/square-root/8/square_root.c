#include "square_root.h"

__attribute__((hot, pure))
extern unsigned square_root(const unsigned n) {
  unsigned x0 = n;
  unsigned x1 = (n + 1u) >> 1;

  while (x1 < x0) {
    x0 = x1;
    x1 += n / x0;
    x1 >>= 1;
  }

  return x0;
}
