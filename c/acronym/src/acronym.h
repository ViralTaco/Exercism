#ifndef VT_ACRONYM_H
#define VT_ACRONYM_H

#ifdef TEST_IGNORE
#  undef TEST_IGNORE
#endif

#define TEST_IGNORE()


#include <stdbool.h> /* bool, true, false */

/* Technically the following function is UB… */
static inline bool is_token(char);
extern char* abbreviate(char const*);

#endif
