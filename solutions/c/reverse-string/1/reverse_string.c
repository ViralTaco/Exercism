/// copyright 2026 viraltaco_ <https://anth.pro>
#include "reverse_string.h"
#include <stddef.h> // size_t
#include <string.h> // strlen
#include <iso646.h> // and, or, not,...
#include <stdlib.h>

char* reverse(char const* value) {
  if (!value) return nullptr;
  size_t kLen = strlen(value);
  
  char* ret = calloc(kLen + sizeof '\0', 1UL);
  if (!ret)           return nullptr;
  else if (kLen == 0) return ret;
  
  char* p = ret;
  char const* end = value + kLen;
  while (kLen--) *p++ = *--end;
  
  return ret;
}
