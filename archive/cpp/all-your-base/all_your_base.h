#ifndef VT_BASES_H
#define VT_BASES_H
#define EXERCISM_RUN_ALL_TESTS

#include <vector>
#include <cstdint>

namespace all_your_base {
std::vector<unsigned int> convert(const unsigned int base_in
, const std::vector<unsigned int>& number
, const unsigned int base_out
);
} // namespace all_your_base

#endif
