/**
 * Copyright (c) 2019 viraltaco
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */


#ifndef VT_SECRET_HANDSHAKE_H
#define VT_SECRET_HANDSHAKE_H

#define EXERCISM_RUN_ALL_TESTS 1

#include <array>
#include <vector>
#include <string>
#include <string_view>

namespace secret_handshake {
enum handshakes {
  wink            = 0b1
, double_blink    = 0b10
, close_eyes      = 0b100
, jump            = 0b1000
, reverse         = 0b1'0000
};

struct secret_combo {
public:
  handshakes shake;
  std::string_view text;
  
  constexpr secret_combo(handshakes shake, std::string_view str) noexcept
    : shake{ shake }, text{ str }
  {}
};

static constexpr std::array<secret_combo, 4ULL> kSecrets{
  secret_combo{ handshakes::wink         , "wink"            }
, secret_combo{ handshakes::double_blink , "double blink"    }
, secret_combo{ handshakes::close_eyes   , "close your eyes" }
, secret_combo{ handshakes::jump         , "jump"            }
};

std::vector<std::string> commands(int);
}  // namespace secret_handshake

#endif // VT_SECRET_HANDSHAKE_H
