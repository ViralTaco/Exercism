/*
 * Copyright (c) 2019 ViralTaco
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_GRAINS_H
#define VT_GRAINS_H

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

namespace grains {
constexpr unsigned long long square(const unsigned int square) noexcept
{
  return (square == 0 || square > 64) ? 0 : 1ULL << (square - 1);
}

constexpr unsigned long long total() noexcept
{
  #if (__cplusplus >= 201402L) // C++14 or above
    unsigned long long result = 0;
    for (unsigned int u = 1; u <= 64; ++u) {
      result += square(u);
    }
    return result;
  #else
    // Same thing but hardcoded -> (2^64) as unsigned long long literal 
    return 18446744073709551615ULL;
  #endif
}

} // namespace grains

#endif
