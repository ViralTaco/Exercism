/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_WORD_COUNT_H
#define VT_WORD_COUNT_H
#define EXERCISM_RUN_ALL_TESTS 1

#include <map>
#include <string>
#include <vector>


namespace word_count {

std::map<std::string, int> words(const std::string& word_str);
[[nodiscard]] std::vector<std::string> parse_words(const std::string& str);

} // namespace word_count

#endif
