#pragma once
#define EXERCISM_RUN_ALL_TESTS

#include <string>
#include <cctype>

namespace atbash {
static constexpr char kAlphabet[]{"zyxwvutsrqponmlkjihgfedcba"};

std::string encode(const std::string& plaintext, bool is_encode = true)
{
  std::string ciphertext;
  int i{0};
  
  for (const auto& c: plaintext) {    
    if (std::isalnum(c)) {
      if (is_encode && i != 0 && i % 5 == 0)
        ciphertext += ' ';
      
      if (std::isdigit(c)) {
        ciphertext += c;
      } else { // if isalpha(c)
        ciphertext += kAlphabet[std::tolower(c) - 'a'];
      }
      ++i;
    }
  }
  return ciphertext;
}

std::string decode(const std::string& ciphertext)
{
  return encode(ciphertext, false);
}

} // namespace atbash
