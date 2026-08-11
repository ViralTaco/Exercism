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

/**
 * @description This function transposes the characters from first to last
 * using a substitution map. It copies each character, in order,
 * using the value of each character as an index into the substitution map.
 *
 * @note This function is intented for file-local use only.
 *
 * @attention If the value doesn't exist in the substitution map the behavior is undefined.
 *
 * @attention If first comes after last the behavior is undefined.
 *
 * @attention If last is not accessible by incrementing first the behavior is
 * undefined.
 *
 * @attention If dest is not a heap allocated,
 * zero initialized (eg: as a result of calling `calloc`),
 * contiguous container of size <code>1 + strlen(first)</code>,
 * or if dest points to a memory location that is within the range
 * [first, last) the behavior is undefined.
 *
 * @param first A pointer to the first character of the string
 * @param last  A pointer to the nul byte of the string
 * @param dest  A pointer to a contiguous array of char with an equal size
 *              to the string, initialized to 0.
 * @return      A pointer to the first character of the destination array.
 */
static char* swap_into(char const* first, char const* last, char* dest) {
  vt_guard(first && last && dest);

  typedef unsigned char uchar;
  static const uchar map[UCHAR_MAX + 1u] =
  { [adenine]  = uracil
  , [cytosine] = guanine
  , [guanine]  = cytosine
  , [thymine]  = adenine,
  };

  uchar* init = (uchar*) dest;
  for (; first != last; ++first, ++init) {
    *init = map[(size_t) *first];
  }

  return dest;
}

extern char* to_rna(char const* dna) {
  vt_guard(dna);
  
  const size_t kLength = strlen(dna);
  char* dest = (char*) calloc(/*size*/ kLength + 1u, /*align*/ 1u);
  vt_guard(dest);
  
  char const* last = dna + kLength;
  return swap_into(dna, last, dest);
}

#undef vt_guard
