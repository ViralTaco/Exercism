/// copyright 2021,2026 viraltaco_ <https://opensource.org/licenses/MIT>
#include "pangram.h"
#include <stddef.h> // NULL macro

bool is_pangram(char const* s) {
  if (s == NULL) return false;
    
  unsigned long int bits = 0ul;
  for (; *s; ++s) {
    const unsigned char c = (*s | 0x20) - 'a';
    if (c >= 26) continue;
    bits |= 1 << c;
  }
  return bits == 0x03FFFFFF;
}
