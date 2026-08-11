#include <benchmark/benchmark.h>
#include "../parallel_letter_frequency.h"
#include "../v1_1_0_parallel_letter_frequency.h"

#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <random>

static void BM_ParallelLetterFrequency_v1_1_1(benchmark::State& state) {
    std::vector<std::string> texts;
    std::vector<std::string_view> views;
    std::mt19937 rng(42);
    std::uniform_int_distribution<> distrib(32, 126);

    const int num_strings = 10;
    const size_t length = state.range(0);

    for (int i = 0; i < num_strings; ++i) {
        texts.emplace_back(length, 'x');
        std::generate_n(
            texts.back().begin(), texts.back().length(),
            [&rng, &distrib]() { return static_cast<char>(distrib(rng)); });
        views.emplace_back(texts.back());
    }

    for (auto _ : state) {
        auto result = parallel_letter_frequency::frequency(views);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_ParallelLetterFrequency_v1_1_1)->RangeMultiplier(10)->Range(1024, 1024 * 1024 * 10);

static void BM_ParallelLetterFrequency_v1_1_0(benchmark::State& state) {
    std::vector<std::string> texts;
    std::vector<std::string_view> views;
    std::mt19937 rng(42);
    std::uniform_int_distribution<> distrib(32, 126);

    const int num_strings = 10;
    const size_t length = state.range(0);

    for (int i = 0; i < num_strings; ++i) {
        texts.emplace_back(length, 'x');
        std::generate_n(
            texts.back().begin(), texts.back().length(),
            [&rng, &distrib]() { return static_cast<char>(distrib(rng)); });
        views.emplace_back(texts.back());
    }

    for (auto _ : state) {
        auto result = parallel_letter_frequency::v1_1_0::frequency(views);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK(BM_ParallelLetterFrequency_v1_1_0)->RangeMultiplier(10)->Range(1024, 1024 * 1024 * 10);

BENCHMARK_MAIN();
