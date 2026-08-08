#ifndef VT_RNA_TRANSCRIPTION_H // copyright 2021,2026 viraltaco_ <https://anth.pro>
#define VT_RNA_TRANSCRIPTION_H "com.viraltaco.c.rna-transcription v" "2.0.0"
/**
 * @description This function transposes the characters from first to last
 * using the SwapMap (aka substitution map). It copies each character, in order,
 * using the value of each character as an index into the substitution map.
 *
 * @note This function is intented for file-local use only.
 *
 * @attention If the value doesn't exist in the substitution map or the map
 * is NULL the behavior is undefined.
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
 * @param map   An exhaustive substitution map (ie: a map which references
 *              every possible value of an unsigned char).
 * @return      A pointer to the first character of the destination array.
 * @see SwapMap
 */
extern char* to_rna(char const* dna);
#endif  // VT_RNA_TRANSCRIPTION_H
