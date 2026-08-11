// copyright 2021,2026 viraltaco_ <https://anth.pro>
#include "rna_transcription.h" // SwapMap
#include <string.h>            // strlen, size_t
#include <stdlib.h>            // calloc
#include <assert.h>            // assert
#include <limits.h>            // UCHAR_MAX
#include <stdio.h>             // fprintf
#include <stdbool.h>           // bool, true, false

enum Nucleobase
{ adenine  = 'A'
, cytosine = 'C'
, guanine  = 'G'
, thymine  = 'T'
, uracil   = 'U'
};

static void vt_guard_impl(const bool condition, char const condition_str[], char const func[]) {
  if (false == condition) {
    (void) fprintf(stderr, "Fatal error: \"%s\".\n\tIn %s function.\n", condition_str, func);
    exit(EXIT_FAILURE);
  }
}
#define vt_guard(COND) (vt_guard_impl((COND), #COND, __func__))

static char* swap_into(char const* first, char const* last, char* dest) {
  vt_guard(first && last && dest);
  
  typedef const unsigned char SwapMap[UCHAR_MAX + 1u];
  static const SwapMap map =
  { [adenine]  = uracil
  , [cytosine] = guanine
  , [guanine]  = cytosine
  , [thymine]  = adenine,
  };

  unsigned char* init = (unsigned char*) dest;
  for (; first != last; ++first, ++init) {
    *init = map[(unsigned) *first];
  }

  return dest;
}

char* to_rna(char const* dna) {
  vt_guard(dna);
  
  const size_t kLength = strlen(dna);
  char* dest = calloc(/*size*/ kLength + 1u, /*align*/ 1u);
  vt_guard(dest);
  
  char const* last = dna + kLength;
  return swap_into(dna, last, dest);
}
#undef vt_guard
