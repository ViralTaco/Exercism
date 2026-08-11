#pragma once
#define EXERCISM_RUN_ALL_TESTS

#include <array>
#include <string>
#include <vector>

#include <locale> // std::locale::classic(), std::isalpha(), std::tolower()
#include <utility> // std::move()
#include <algorithm> // std::transform()

namespace anagram {
class anagram {
private:
  const std::string word_;
  const std::array<int, 26> letter_count_;

public: // constructor
  explicit anagram(std::string word)
    : word_{ as_lower(std::move(word)) }
    , letter_count_{ count_letters(word_) }
  {}
  
public: // methods
  std::vector<std::string>
  matches(const std::vector<std::string>& word_list) const {
    std::vector<std::string> match_list{};
    
    for (const auto& s: word_list)
      if (is_anagram(as_lower(s)))
        match_list.push_back(s);
        
    return match_list;
  }

private: // methods
  bool is_anagram(const std::string& str) const noexcept {
    return word_.length() == str.length()
       and word_ != str
       and letter_count_ == count_letters(str)
    ;
  }

  std::string as_lower(std::string s) const noexcept {
    std::transform(s.begin(), s.end(), s.begin()
    , [] (auto c) { return std::tolower(c, std::locale::classic()); }
    );
    return s;
  }
  
  std::array<int, 26> count_letters(const std::string& str) const noexcept {
    std::array<int, 26> count{};
    for (const auto c: str)
      if (std::isalpha(c, std::locale::classic()) != 0)
        ++count[(c - 'a')];

    return count;
  }
}; // class anagram

} // namespace anagram
