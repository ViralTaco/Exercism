/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "nucleotide_count.h"

dna::counter::counter(const std::string& dna_str)
{
  for (const auto nucleotide: dna_str)
    switch (nucleotide) {
      case 'A': 
        adenine_count += 1;
        break;
      case 'C': 
        cytosine_count += 1;
        break;
      case 'G': 
        guanine_count += 1;
        break;
      case 'T': 
        thymine_count += 1;
        break;
        
      default: 
        throw std::invalid_argument("not a nucleotide.");
    }
}

unsigned dna::counter::count(const char nucleotide_id) const
{
  switch (nucleotide_id) {
    case 'A': 
      return adenine_count;
    case 'C': 
      return cytosine_count;
    case 'G': 
      return guanine_count;
    case 'T': 
      return thymine_count;
  }
  throw std::invalid_argument("not a nucleotide.");
}

std::map<char, int> dna::counter::nucleotide_counts() const
{
  return { {'A', adenine_count  }
         , {'T', thymine_count  }         
         , {'C', cytosine_count }
         , {'G', guanine_count  } }
  ;
}
