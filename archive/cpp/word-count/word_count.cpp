/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "word_count.h"
#include <cctype>

namespace word_count {

std::vector<std::string> parse_words(const std::string& str)
{
  std::vector<std::string> word_arr{""};
  std::size_t count{0};
  bool is_compound_word{ false };
  
  for (const auto c: str) {
    if (is_compound_word and std::isalpha(c)) {
      word_arr[count] += '\'';
      word_arr[count] += std::tolower(c);
      is_compound_word = false;
      continue;
    }
    
    if (std::isalnum(c)) {
      word_arr[count] += std::tolower(c);
    } else if ((c == ' ' or c == ',' or c == '\n') 
           and not word_arr[count].empty()) {
      word_arr.push_back("");
      count++;
    } else if (c == '\'' and not word_arr[count].empty()) {
      is_compound_word = true;
    }
  }
  
  return word_arr;
}

std::map<std::string, int> words(const std::string& word_str)
{
  std::map<std::string, int> word_map;
  
  for (const auto& word: parse_words(word_str)) {
    if (not word_map[word])
      word_map.emplace(word, 0);
    
    word_map[word]++;
  }
  
  return word_map;
}

} // namespace word_count
