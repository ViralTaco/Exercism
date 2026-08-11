/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_CRYPTO_SQUARE_H
#define VT_CRYPTO_SQUARE_H

#define EXERCISM_RUN_ALL_TESTS 1

#include <vector>
#include <string>
#include <utility>

namespace crypto_square {

struct dimentions {
  int rows;
  int collumns;
  
  dimentions(int size);
  
  int size() const noexcept;
};

class cipher {
private: 
  std::pair<std::string, int> normalized_;
  
  dimentions dimentions_;
  
  std::string cleartext_;
  
  std::vector<std::string> cipher_square_{};
  std::vector<std::string> cleartext_square_{};

public:
  cipher(const std::string& cleartext);
  
  std::pair<std::string, int> normalize(const std::string& text) const;
  
  std::vector<std::string> 
  rotate(const std::vector<std::string>& square, int rows) const;
  
public: // getters
  // ciphertext no spaces.
  std::string cipher_text() const;
  
  // cipher_square_ in one string separated with spaces
  std::string normalized_cipher_text() const; 
  
  // cleartext_
  std::string normalize_plain_text() const noexcept;
  
  // cleartext_square_
  std::vector<std::string> plain_text_segments() const noexcept;
};

} // namespace crypto_square

#endif
