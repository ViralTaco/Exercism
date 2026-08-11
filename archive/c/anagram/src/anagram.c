#include "anagram.h"

#include <iso646.h>   /* and, or, not */

#include <ctype.h>    /* isalpha() */
#include <stdlib.h>   /* calloc() */
#include <string.h>   /* strlen(), tolower()*/

char* as_lower(char const* str) {
  if (str == NULL or *str == '\0')
    return NULL;
    
  char *out = calloc(strlen(str) + 1ULL, 1ULL);
  
  if (out != NULL)
    for (int i = 0; *str; ++i, ++str)
      out[i] = (char) tolower(str[i]);
  
  return out;
}

int count_letters(int (*const arr_ptr)[kLen], char const* word) {
  const int word_len = (int) strlen(word);
  int *arr = *arr_ptr;
  
  
  for (int i = 0; i < word_len; ++i) {
    const char letter = word[i];
    if (isalpha(letter))
      ++arr[(letter - 'a')];
  }
  
  return kWordLen;
}

bool isanagram(char const* word, char const* other) {
  int count[kLen] = { 0 };
  const int kCandLen = count_letters(&count, other);
  
  if (kWordLen != kCandLen
  or strncmp(word, other, (size_t) kWordLen) == 0) 
    return false;
  
  for (int i = 0; i < kLen; ++i) 
    if (letter_count[i] != count[i]) 
      return false;
  
  return true;
}

#define handle_calloc_failure(ptr, ptr_to_be_freed) do {     \
  if (ptr == NULL) {                                         \
    free(ptr_to_be_freed);                                   \
    exit(EXIT_FAILURE);                                      \
  }                                                          \
} while (false)

void anagrams_for(char* word, struct candidates* candidates) {
  char const* lowercased = as_lower(word);
  handle_calloc_failure(lowercased, NULL);
  kWordLen = count_letters(&letter_count, lowercased);
  
  const int candidate_count = (int) candidates->count;
  struct candidate *c_ptr = candidates->candidate;
  
  for (int i = 0; i < candidate_count; ++i) {
    char const* lowered_candidate = as_lower(c_ptr[i].candidate);
    handle_calloc_failure(lowered_candidate, lowercased);
    
    c_ptr[i].is_anagram = isanagram(lowercased, lowered_candidate)
      ? IS_ANAGRAM : NOT_ANAGRAM;
      
    free(lowered_candidate);
  }
  
  free(lowercased);
}

#undef handle_calloc_failure
