#ifndef VT_PANGRAM_H
#define VT_PANGRAM_H

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <string>

namespace pangram {
bool is_pangram(const std::string& str);
} // namespace pangram

#endif
