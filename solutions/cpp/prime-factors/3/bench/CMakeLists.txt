cmake_minimum_required(VERSION 3.14)
project(prime_factors_benchmarks CXX)

# Set C++ standard matching the main project (C++26 with extensions off)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Enable FetchContent
include(FetchContent)

# Declare Google Benchmark dependency
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.9.5
)

# Disable build of tests, install target, and internal documentation of Google Benchmark
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Enable testing of the benchmark library" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "Enable installation of benchmark" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "Enable building the unit tests" FORCE)

# Download and make the dependency available
FetchContent_MakeAvailable(benchmark)

# Add the benchmark executable
add_executable(prime_factors_benchmark benchmark.cpp)

# Header-only library is in the includes directory
target_sources(prime_factors_benchmark PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/v1_1_0/prime_factors.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../prime_factors.h
)
# Link against the Google Benchmark target
target_link_libraries(prime_factors_benchmark PRIVATE benchmark::benchmark)
