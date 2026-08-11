#ifndef VT_ALLERGIES_H
/*
 * Copyright (c) 2019,2026 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */
#define VT_ALLERGIES_H
#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <array>
#include <bitset>
#include <string_view>
#include <unordered_set>

namespace allergies {
struct allergy_test {
public:
  std::bitset<8> is_allergic_;
  
  explicit constexpr allergy_test(const std::size_t score) noexcept
    : is_allergic_(score)
  {}
  
  static constexpr auto kAllergies = std::array<std::string_view, 8u>{
    "eggs", "peanuts", "shellfish", "strawberries"
  , "tomatoes", "chocolate", "pollen", "cats"
  };
  
  constexpr auto is_allergic_to(const std::string_view name) noexcept -> bool {
    auto allergy_id = 0u;

    for (auto const& s: kAllergies) {
      if (name == s) break;
      ++allergy_id;
    }
    
    return allergy_id < is_allergic_.size() and is_allergic_[allergy_id];
  }
  
  auto get_allergies() const noexcept -> std::unordered_set<std::string> {
    std::unordered_set<std::string> result;
    
    for (std::size_t i{}; i != 8; ++i)
      if (is_allergic_[i])
        result.insert(std::string(kAllergies[i]));
    
    return result;
  }
};

} // namspace allergies

#endif
