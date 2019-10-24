#pragma once
#define EXERCISM_RUN_ALL_TESTS

#include <string>
#include <array>
#include <vector>
#include <cstddef>   // std::size_t

#include <algorithm> // std::transform()
#include <cstring>   // std::tolower()
#include <cctype>    // std::isalpha()

namespace anagram {
class anagram {
private:
  const std::string word_;
  const std::array<int, 26> letter_count_;

public: // constructor
  anagram(std::string word)
    : word_{ as_lower(word) }
    , letter_count_{ count_letters(word_) }
  {}
  
public: // methods
  auto matches(const std::vector<std::string>& word_list) {
    std::vector<std::string> match_list{};
    
    for (const auto& s: word_list)
      if (is_anagram(as_lower(s)))
        match_list.push_back(s);
        
    return match_list;
  }
  
  bool is_anagram(const std::string& str) const noexcept {
    return word_ .length() == str.length()
       and word_ != str
       and letter_count_ == count_letters(str)
    ;
  }
  
private: // methods
  std::string as_lower(std::string s) const {
    std::transform(s.begin(), s.end(), s.begin()
    , [] (unsigned char c) { return std::tolower(c); }
    );
    return s;
  }
  
  std::array<int, 26> count_letters(const std::string& str) const noexcept {
    std::array<int, 26> count{};
    for (const unsigned char c: str)
      if (std::isalpha(c) != 0)
        ++count[(c - 'a')];

    return count;
  }
}; // class anagram

} // namespace anagram
