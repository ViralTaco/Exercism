#ifndef VT_SECRET_HANDSHAKE_H
/**
* Copyright (c) 2019,2026 viraltaco
* SPDX-License-Identifier: MIT
* <http://www.opensource.org/licenses/MIT>
*/
#define VT_SECRET_HANDSHAKE_H

#include <array>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm> // std::reverse
#include <cstddef>


namespace secret_handshake {

struct SecretCombo {
public:
  enum Handshake {
      wink            = 0b0000'0001
    , double_blink    = 0b0000'0010
    , close_eyes      = 0b0000'0100
    , jump            = 0b0000'1000
    , reverse         = 0b0001'0000
  };
  
  Handshake shake;
  std::string_view text;
  
  constexpr SecretCombo(const Handshake shake, const std::string_view str) noexcept
    : shake{ shake }
    , text{ str }
  {}
};

static constexpr std::array<SecretCombo, 4ULL> kSecrets{
  { // secret_combo
    { SecretCombo::Handshake::wink         , "wink"            }
  , { SecretCombo::Handshake::double_blink , "double blink"    }
  , { SecretCombo::Handshake::close_eyes   , "close your eyes" }
  , { SecretCombo::Handshake::jump         , "jump"            }
  } 
};

constexpr auto commands(const int command) noexcept -> std::vector<std::string> {
  std::vector<std::string> handshakes;
  
  for (auto const& [handshake, secret]: kSecrets) {
    if (command & handshake) {
      handshakes.emplace_back(secret);
    }
  }
  
  if (command & SecretCombo::Handshake::reverse) {
    std::reverse(handshakes.begin(), handshakes.end());
  }
  
  return handshakes;
}
}  // namespace secret_handshake

#endif // VT_SECRET_HANDSHAKE_H
