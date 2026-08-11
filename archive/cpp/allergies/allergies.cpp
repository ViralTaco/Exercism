/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "allergies.h"

static const std::string kAllergies[]{
  "eggs", "peanuts", "shellfish", "strawberries"
, "tomatoes", "chocolate", "pollen", "cats"
};

using allergies::allergy_test;

bool allergy_test::is_allergic_to(const std::string& name)
{
  std::size_t allergy_id{0};
  
  for (const auto& s: kAllergies) {
    if (name == s) {
      break;
    }
    ++allergy_id;
  }
  
  return allergy_id < 8 && this->is_allergic_[allergy_id];
}

std::unordered_set<std::string> allergy_test::get_allergies()
{
  std::unordered_set<std::string> result;
  
  for (std::size_t i{0}; i < 8; ++i)
    if (this->is_allergic_[i])
      result.insert(kAllergies[i]);
  
  return result;
}
