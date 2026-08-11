/*
 * Copyright (c) 2019 viraltaco
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */
#pragma once
#define EXERCISM_RUN_ALL_TESTS
#include <string>

namespace beer_song {

constexpr auto kOnTheWall{ " of beer on the wall." };
constexpr auto kBeersOnWall{ " bottles of beer on the wall, " };
constexpr auto kTakeOneDown{ 
  " bottles of beer.\nTake one down and pass it around, " 
};

constexpr auto kLastBottle{ 
  "1 bottle of beer on the wall, 1 bottle of beer.\n"
  "Take it down and pass it around, no more bottles of beer on the wall.\n"
};
constexpr auto kNoMoreBeer{
  "No more bottles of beer on the wall, no more bottles of beer.\n"
  "Go to the store and buy some more, 99 bottles of beer on the wall.\n"
};



std::string verse(const unsigned);
std::string sing(int begin, const int end = 0);
  
} // namespace beer_song
