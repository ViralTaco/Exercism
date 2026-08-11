/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "crypto_square.h"

#include <cmath>
#include <cctype>
#include <numeric>

namespace crypto_square {

dimentions::dimentions(int size)
  : rows{0}
  , collumns{0}
{
  if (size != 0) {
    rows = static_cast<int>(std::sqrt(size));
    collumns = (size % rows == 0) ? rows : rows + 1;
  }
}

int dimentions::size() const noexcept
{ return rows * collumns; }

std::pair<std::string, int> 
cipher::normalize(const std::string& text) const
{
  std::pair<std::string, int> normalized{"", 0};
  
  for (const auto c: text) {
    if (std::isalnum(c)) {
      normalized.first += std::tolower(c);
      normalized.second++;
    } 
  }
  
  return normalized;
}

cipher::cipher(const std::string& cleartext)
  : normalized_{ cipher::normalize(cleartext) }
  , dimentions_{ normalized_.second }
  , cleartext_{ normalized_.first }
{
  if (normalized_.second == 0) {
    cleartext_square_ = {};
    cipher_square_ = {};
    return;
  }
  
  int substring_start{0};
  for (int x{0}; x < dimentions_.rows; ++x) {
    cleartext_square_.push_back(
      cleartext_.substr(substring_start, dimentions_.collumns)  
    );
    substring_start += dimentions_.collumns;
  }
  
  cipher_square_ = rotate(cleartext_square_, dimentions_.rows);
}

std::vector<std::string> 
cipher::rotate(const std::vector<std::string>& square, int rows) const
{
  std::vector<std::string> rotated{
    static_cast<std::size_t>(dimentions_.collumns)
  };
  
  for (int x{0}; x < dimentions_.collumns; ++x) {
    for (int y{0}; y < rows; ++y)
      if (std::isalnum(square[y][x])) 
        rotated[x] += square[y][x];
  }
  
  return rotated;
}

// ciphertext no spaces.
std::string cipher::cipher_text() const
{
  std::string cipher_str;
  
  for (const auto& s: cipher_square_)
    cipher_str += s;
    
  return cipher_str;
}

// cipher_square_ in one string separated with spaces
std::string cipher::normalized_cipher_text() const
{
  std::string cipher_str;
  
  for (const auto& s: cipher_square_)
    cipher_str += s + " ";
  
  cipher_str.pop_back(); // remove extranious space
  return cipher_str;
}

// cleartext_
std::string cipher::normalize_plain_text() const noexcept
{ return cleartext_; }

// cleartext_square_
std::vector<std::string> cipher::plain_text_segments() const noexcept
{ return cleartext_square_; }

} // namespace crypto_square
