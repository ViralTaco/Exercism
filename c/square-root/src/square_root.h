#ifndef VT_SQUARE_ROOT_H
#define VT_SQUARE_ROOT_H

#if (defined(__clang__) && __has_attribute(hot)) || \
  (!defined(__clang__) && defined(__GNUC__))
#  define HOT __attribute__((hot))
#else
#  define HOT /* cold */
#endif

#ifdef TEST_IGNORE
#  undef TEST_IGNORE
#  define TEST_IGNORE()
#endif

extern unsigned squareRoot(const unsigned) HOT;
extern unsigned square_root(const unsigned) HOT;


#endif
