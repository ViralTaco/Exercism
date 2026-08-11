#include "acronym.h"

#include <stdlib.h>  /* malloc() */
#include <string.h>  /* strlen() */
#include <ctype.h>   /* isalpha(), toupper() */

#include <iso646.h>  /* and, or */

static inline bool is_token(char c) {
  return c == ' ' or c == '-';
}

char* abbreviate(char const* phrase) {
  char *buff = NULL;
  
  if (phrase == NULL or *phrase == '\0'
  or (buff = malloc(strlen(phrase))) == NULL)
    return NULL;
    
  *buff = (char) toupper(*phrase);
  size_t pos = 1ULL;
  
  while (*(++phrase)) 
    if (is_token(*(phrase - 1ULL)) and isalpha(*phrase))
      buff[pos++] = (char) toupper(*phrase);
    
  return buff;
}
