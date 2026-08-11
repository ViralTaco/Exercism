#pragma once
#define EXERCISM_RUN_ALL_TESTS

#include <cstdlib>
#include <errno.h>

namespace trinary {
unsigned long to_decimal(const char* t_ptr)
{
  // Honestly I can't be harsed to reinvent the wheel
  char *end;
  unsigned long result{std::strtoul(t_ptr, &end, 3)};

  // if error: reset errno then return it (0) else return result
  return (ERANGE == errno) ? (errno = 0) : result;
}

} // namespace trinary