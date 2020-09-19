#include "nth_prime.h"

#include <stdexcept>

#include "test/catch.hpp"

TEST_CASE("first") { REQUIRE(2 == nth_prime::nth(1)); }

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("second") { REQUIRE(3 == nth_prime::nth(2)); }

TEST_CASE("sixth") { REQUIRE(13 == nth_prime::nth(6)); }

TEST_CASE("big_prime") { REQUIRE(104743 == nth_prime::nth(10001)); }

TEST_CASE("weird_case") {
  REQUIRE_THROWS_AS(nth_prime::nth(0), std::domain_error);
}

#if defined(VT_TEST_FIRST_NTH)
#if VT_TEST_FIRST_NTH < 0
#undef VT_TEST_FIRST_NTH
#define VT_TEST_FIRST_NTH 9593
#endif
TEST_CASE("test_primes_under_100k") {
  static constexpr unsigned kPrimes[9593] = {
      0,  // [0] is invalid.
      // Buckle your seatbelt, Dorothy, 'cause Kansas is going bye-bye.
#include "primes_under_100k.csv"
  };

  for (auto i = 1ul; i < VT_TEST_FIRST_NTH; ++i) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-compare"
    REQUIRE(kPrimes[i] == nth_prime::nth(i));
#pragma clang diagnostic pop
  }
}
#endif  // defined (VT_TEST_FIRST_NTH)

#endif
