/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_ALLERGIES_H
#define VT_ALLERGIES_H
#define EXERCISM_RUN_ALL_TESTS

#include <string>
#include <unordered_set>

namespace allergies {

struct allergy_test {
public:
  bool is_allergic_[8];
  
  allergy_test(const std::size_t score)
  {
    for (std::size_t i{0}; i < 8; ++i) 
      is_allergic_[i] = (score >> i) & 1; 
  }
  
  bool is_allergic_to(const std::string& name);
  std::unordered_set<std::string> get_allergies();
};

} // namspace allergies

#endif
