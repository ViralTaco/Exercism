#ifndef VT_LEAP_H
#define VT_LEAP_H

#if (defined(__clang__) && __has_attribute(hot)) || \
  (!defined(__clang__) && defined(__GNUC__))
#  define HOT __attribute__((hot))
#else
#  define HOT /* cold */
#endif

#ifdef TEST_IGNORE
#  undef TEST_IGNORE
#endif

#define TEST_IGNORE()

#include <stdbool.h>

extern bool is_leap_year(int year) HOT;

#endif
