/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_NUCLEOTIDE_COUNT_H
#define VT_NUCLEOTIDE_COUNT_H
#define EXERCISM_RUN_ALL_TESTS

#include <string>
#include <map>

namespace dna {
  
struct counter {
public:
  unsigned cytosine_count{};
  unsigned adenine_count{};
  unsigned guanine_count{};
  unsigned thymine_count{};
  
  counter(const std::string& dna_str);
  
  unsigned count(const char nucleotide_id) const;
  std::map<char, int> nucleotide_counts() const;
};

} // namespace dna

#endif
