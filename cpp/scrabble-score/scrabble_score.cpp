/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "scrabble_score.h"
#include <cctype>
#include <numeric>

unsigned int scrabble_score::score(const std::string& word)
{
  return std::accumulate(word.begin(), word.end(), 0U // count from 0
  , [] (int acc, char c) -> unsigned int
  {
    switch (std::tolower(c)) {
      case 'a': case 'e': case 'i': 
      case 'o': case 'u': case 'l': 
      case 'n': case 'r': case 's': 
      case 't':
        return acc + 1;
      case 'd': case 'g':
        return acc + 2;
      case 'b': case 'c': case 'm':
      case 'p':
        return acc + 3;
      case 'f': case 'h': case 'v':
      case 'w': case 'y': 
        return acc + 4;
      case 'k':
        return acc + 5;
      case 'j': case 'x':
        return acc + 8;
      case 'q': case 'z':
        return acc + 10;
      default:
        return acc;
    }
  });
}
