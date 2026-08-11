#ifndef VT_NTH_PRIME_H
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ nth_prime.h:                                         ┃
// ┃ Copyright (c) 2019 - 2020 viraltaco_                 ┃
// ┃ SPDX-License-Identifier: MIT                         ┃
// ┃ <http://www.opensource.org/licenses/MIT>             ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#define VT_NTH_PRIME_H "2.1.1"
#define EXERCISM_RUN_ALL_TESTS
#define VT_TEST_FIRST_NTH (-1) // Test all.

#include <cstddef>   // std::size_t
#include <cstdint>   // std::uint64_t

#include <array>     // std::array
#include <string>    // std::{ string, to_string, ""s }
#include <stdexcept> // std::out_of_range

namespace nth_prime {
using u64 = std::uint64_t;

struct Wheel {
  static constexpr auto primes = std::array {
    2ul, 3ul, 5ul, 7ul, 11ul, 13ul, 17ul, 19ul, 23ul,
    29ul, 31ul, 37ul, 41ul, 43ul, 47ul, 53ul, 59ul,
    61ul, 67ul, 71ul, 73ul, 79ul, 83ul, 89ul, 97ul,
  };
  static constexpr auto
    size  = primes.size(),
    last  = primes.back(),
    first = primes.front();
  
  template <class SizeType = const std::size_t> [[nodiscard]]
  static constexpr auto get(SizeType pos) {
    using namespace std;
    if (pos > size) {
      throw out_of_range(
        R"(Wheel::get(P): 'P' cannot be over ')"s + to_string(size) + "'.\n");
    } else {
      return primes[ pos - 1 ];
    }
  }
};

[[nodiscard]] auto nth(u64) -> u64;
[[nodiscard]] auto is_prime(u64) noexcept -> bool;
} // namespace nth_prime

/* References:
     - Sieve of Eratosthenes: https://w.wiki/cYa
     - Primes under 100'000: https://primes.utm.edu/lists/small/10000.txt
 * For Future use:
     - Elliptic Curves (Professor Toby Gee): https://youtu.be/6eZQu120A80
     - Baillie-PSW: https://w.wiki/cYb
 * Benchmarks:
     - nth_prime::is_prime vs. gnu mp's isprime:
        https://quick-bench.com/q/OynyBgZXNsGA73e9QUlIuOdFTrg
 */

#endif
