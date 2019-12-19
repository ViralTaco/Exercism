#ifndef ARMSTRONG_NUMBERS
#define ARMSTRONG_NUMBERS

#include <stdbool.h>

#if (defined(__clang__) && __has_attribute(hot)) || \
    (!defined(__clang__) && defined(__GNUC__))
#  define HOT __attribute__((hot))
#else
#  define HOT /* cold */
#endif

extern bool is_armstrong_number(int) HOT; 

#endif
