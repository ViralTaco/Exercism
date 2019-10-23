/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_NTH_PRIME_H
#define VT_NTH_PRIME_H
#define EXERCISM_RUN_ALL_TESTS

#include <cstdlib>

namespace prime {
std::size_t nth(std::size_t n);

template <typename T> bool is_prime(T x);
} // namespace prime

#endif
