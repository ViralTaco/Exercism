#include "includes/v1_1_0/prime_factors.h"
#include "../prime_factors.h"
#include <benchmark/benchmark.h>

// Fixture class for Prime Factors benchmarks
class PrimeFactorsFixture : public benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State&) override {
        // Setup code if needed
    }

    void TearDown(const ::benchmark::State&) override {
        // Teardown code if needed
    }
};

// Register the benchmarks with specific test cases:
// 2 - Smallest prime (tests minimal loops)
// 8 - Small power of 2 (tests the specialized even factors loop)
// 27 - Small composite with odd prime factor (power of 3)
// 625 - Medium composite with odd prime factor (power of 5)
// 100003 - Small prime number (worst-case scenario where loop searches up to the prime value itself)
// 901255 - Product of small primes (5 * 17 * 23 * 461)
// 93819012551 - Large product of primes (11 * 9539 * 894119)
#define VT_REGISTER_PF_BENCHMARK(VERSION)\
    BENCHMARK_DEFINE_F(PrimeFactorsFixture, VERSION)                          \
    (benchmark::State& state) {                                               \
        const long long value = state.range(0);                               \
        for (auto _ : state) {                                                \
            auto factors = prime_factors::VERSION::of(value);                 \
            benchmark::DoNotOptimize(factors.data());                         \
            benchmark::ClobberMemory();                                       \
        }                                                                     \
    }                                                                         \
BENCHMARK_REGISTER_F(PrimeFactorsFixture, VERSION)                            \
    ->Arg(2)                                                                  \
    ->Arg(8)                                                                  \
    ->Arg(27)                                                                 \
    ->Arg(625)                                                                \
    ->Arg(100003)                                                             \
    ->Arg(901255)                                                             \
    ->Arg(93819012551)

VT_REGISTER_PF_BENCHMARK(v1_1_0);
VT_REGISTER_PF_BENCHMARK(v2_0_0);
#undef VT_REGISTER_PF_BENCHMARK

BENCHMARK_MAIN();
