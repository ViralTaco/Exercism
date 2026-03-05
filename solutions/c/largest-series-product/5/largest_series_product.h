#ifndef LARGEST_SERIES_PRODUCT_H
#define LARGEST_SERIES_PRODUCT_H

#include <stddef.h> // size_t
#include <stdint.h> // int_least64_t

[[nodiscard]] extern int_least64_t
largest_series_product(char const* digits, const size_t span);

#endif
