/// copyright 2021,2026 viraltaco_ <https://opensource.org/licenses/MIT>
#include "pangram.h"

bool is_pangram(char const* s) {
  unsigned long long bits = 0ull;
  unsigned char c;
  while (s && (c = *s++)) {
    if      ('Z' >= c && c >= 'A') { bits |= 1ull << (c - 'A'); }
    else if ('z' >= c && c >= 'a') { bits |= 1ull << (c - 'a'); }
  }
  return bits == 0x3FFFFFF;
}
