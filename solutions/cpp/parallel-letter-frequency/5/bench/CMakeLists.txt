cmake_minimum_required(VERSION 3.10)
project(LetterFrequencyBenchmarks)

set(CMAKE_CXX_STANDARD 23)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable benchmark tests" FORCE)

include(FetchContent)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.8.3
)
FetchContent_MakeAvailable(benchmark)

add_executable(benchmark_parallel_letter_frequency benchmark.cpp)
target_compile_options(benchmark_parallel_letter_frequency PRIVATE -Wall -Wextra -O3)

target_link_libraries(benchmark_parallel_letter_frequency PRIVATE benchmark::benchmark benchmark::benchmark_main)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    find_package(TBB)
    if (TBB_FOUND)
        target_link_libraries(benchmark_parallel_letter_frequency PRIVATE TBB::tbb)
    endif()
endif()
