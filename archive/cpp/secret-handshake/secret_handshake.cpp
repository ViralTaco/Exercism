/**
 * Copyright (c) 2019 viraltaco
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */

#include "secret_handshake.h"

#include <algorithm> // std::reverse

namespace secret_handshake {

std::vector<std::string> commands(int command) {
  std::vector<std::string> handshakes;
  for (const auto& [handshake, secret]: kSecrets) {
    if (command & handshake)
      handshakes.emplace_back(std::string{ secret });
  }
  
  if (command & handshakes::reverse)
    std::reverse(handshakes.begin(), handshakes.end());
  
  return handshakes;
}
} // namespace secret_handshake
