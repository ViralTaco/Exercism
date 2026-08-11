/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_QUEEN_ATTACK_H
#define VT_QUEEN_ATTACK_H

#define EXERCISM_RUN_ALL_TESTS

#include <utility>
#include <string>

namespace queen_attack {

using position = std::pair<int, int>;

class chess_board {
private:
  position white_;
  position black_;
  
  static constexpr std::size_t kLineLength{ 16 };
  static constexpr char kWhiteToken{ 'W' };
  static constexpr char kBlackToken{ 'B' };
  
public:
  std::string board{
    "_ _ _ _ _ _ _ _\n"
    "_ _ _ _ _ _ _ _\n"
    "_ _ _ _ _ _ _ _\n"
    "_ _ _ _ _ _ _ _\n"
    "_ _ _ _ _ _ _ _\n"
    "_ _ _ _ _ _ _ _\n"
    "_ _ _ _ _ _ _ _\n"
    "_ _ _ _ _ _ _ _\n"
  };

  chess_board(position white = {0, 3}, position black = {7, 3})
    : white_{ white } 
    , black_{ black }
  {
    if (white_ == black_) 
      throw std::domain_error("Two queens one square.");
    
    board[ linear_position(white_) ] = kWhiteToken;
    board[ linear_position(black_) ] = kBlackToken;
  }
  
private: // member functions
  std::size_t linear_position(position pos) const
  { return (pos.first * kLineLength) + (2 * pos.second); }
  
public: // member functions
  bool can_attack() const noexcept
  {
    auto a{ black_.first  - white_.first  };
    auto b{ black_.second - white_.second };
    
    bool match{ black_.first == white_.first };
    match |= black_.first == white_.second;
    match |= black_.second == white_.first;
    match |= black_.second == white_.second;
    
    return a == b || match;
  }

public: // getters
  position white() const noexcept
  { return this->white_; }
  
  position black() const noexcept
  { return this->black_; }
  
public: // operator overloads
  operator std::string() const
  { return this->board; }
};

} // namespace queen_attack 

#endif
