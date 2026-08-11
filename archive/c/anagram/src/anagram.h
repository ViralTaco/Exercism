#ifndef ANAGRAM_H
#define ANAGRAM_H

#ifdef TEST_IGNORE
#  undef TEST_IGNORE
#endif

#define TEST_IGNORE()
#define MAX_STR_LEN 20

#include <stddef.h>   /* size_t */
#include <stdbool.h>  /* bool, true, false */

enum { kLen = 26, };

static int letter_count[kLen];
static int kWordLen;

enum anagram_status {
  UNCHECKED = -1,
  NOT_ANAGRAM = 0,
  IS_ANAGRAM = 1,
};

struct candidate {
  enum anagram_status is_anagram;
  char const* candidate;
};

struct candidates {
  struct candidate* candidate;
  size_t count;
};

extern char* as_lower(char const*);
extern bool isanagram(char const*, char const*);
extern int count_letters(int (*const)[kLen], char const*);
extern void anagrams_for(char*, struct candidates*);
#endif
