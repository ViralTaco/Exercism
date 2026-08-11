#pragma once /// Copyright 2026 viraltaco_ <https://anth.pro>
#ifndef vt_zebra_puzzle_h
#define vt_zebra_puzzle_h "com.viraltaco.zebra-puzzle v" "0.0.1"

#include <string_view>

namespace zebra_puzzle::inline v0_0_1 {
  struct Solution {
    static constexpr auto drinksWater = std::string_view{"Norwegian"};
    static constexpr auto ownsZebra = std::string_view{"Japanese"};
  };
  
  static constexpr auto solve() noexcept -> Solution { return {}; }
}

#endif //ndef vt_zebra_puzzle_h
