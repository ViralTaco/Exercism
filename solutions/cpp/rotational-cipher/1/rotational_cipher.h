#pragma once /// Copyright 2026 viraltaco_ <https://anth.pro>
#ifndef vt_rotational_cipher_h
#define vt_rotational_cipher_h "com.viraltaco.rotational-cipher " "v0.0.1"

#include <string>    // std::string
#include <cstring>   // std::isalpha
#include <cstddef>   // std::size_t
#include <algorithm> // std::transform

namespace rotational_cipher { inline namespace v0_0_1 {
  auto rotate(std::string text, std::size_t key) -> std::string;
}}  // namespace rotational_cipher::inline v0_0_1

#endif //ndef vt_rotational_cipher_h
