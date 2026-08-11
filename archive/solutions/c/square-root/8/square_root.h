#ifndef VT_SQUARE_ROOT_H//copyright 2019,2021,2026 viraltaco_ <https://anth.pro>
#define VT_SQUARE_ROOT_H "com.viraltaco.c.square-root v" "2.0.0"
/**
 * @brief A slower version of sqrt.
 * @param x a positive integer.
 * @return the integer square root of x.
 */
extern unsigned square_root(const unsigned) __attribute((hot, pure));
#endif//ndef VT_SQUARE_ROOT_H
