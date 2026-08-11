/*
 * Copyright (c) 2019 viraltaco
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "beer_song.h"
#include <sstream>

namespace beer_song {

std::string verse(const unsigned bottles) {
  std::string bottle_str = " bottle";
  
  switch (bottles) {
    case 0ULL:
      return kNoMoreBeer;
    case 1ULL:
      return  kLastBottle;
    case 2ULL:
      break;
    default:
      bottle_str += 's';
      break;
  }
  
  std::stringstream song;
  song << bottles << kBeersOnWall << bottles << kTakeOneDown 
       << (bottles - 1U) << bottle_str << kOnTheWall << '\n';

  return song.str();
}

std::string sing(int begin, const int end) {
  if (begin < 0 or end < 0)
    return nullptr;
  
  std::string song;
  for (; begin >= end; --begin)
    song += verse(begin) + '\n';
  
  song.pop_back(); // remove last \n
  return song;
}
  
} // namespace beer_song
