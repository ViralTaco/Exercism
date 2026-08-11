/// copyright 2026 viraltaco_ <https://anth.pro>
#include "reverse_string.h"
#include <stddef.h> // size_t
#include <string.h> // strlen
#include <iso646.h> // and, or, not,...
#include <stdlib.h> // calloc

char* reverse(char const* value) {
  if (!value) return (char*) value;
  
  const size_t len = strlen(value);
  char* ret = calloc(len + sizeof '\0', 1UL);
  if (!ret or !len) return ret;  
  
  for (ret += len; *value; ++value)
    *--ret = *value;
  
  return ret;
}
