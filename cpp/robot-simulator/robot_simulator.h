/*
 * Copyright (c) 2019 viraltaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_ROBOT_SIMULATOR_H
#define VT_ROBOT_SIMULATOR_H

#define EXERCISM_RUN_ALL_TESTS 1

#include <utility>
#include <string_view>

namespace robot_simulator {
enum class Bearing { // clockwise from north
  north
, east
, south
, west
};

class Robot {
private:
  std::pair<int, int> position_;
  Bearing bearing_;
  
public: // constructors
  Robot() noexcept
    : position_{ 0, 0 }
    , bearing_{ Bearing::north }
  {}

  Robot(std::pair<int, int> position, Bearing a_bearing) noexcept
    : position_{ position }
    , bearing_{ a_bearing }
  {}
  
  Robot(Robot&& rhs) noexcept = default;

public: // member functions
  void turn_left() noexcept {
    switch (this->bearing_) {
      case Bearing::north:
        this->bearing_ = Bearing::west;
        break;
      case Bearing::east:
        this->bearing_ = Bearing::north;
        break;
      case Bearing::south:
        this->bearing_ = Bearing::east;
        break;
      case Bearing::west:
        this->bearing_ = Bearing::south;
        break;
    }
  }
  
  void turn_right() noexcept {
    switch (this->bearing_) {
      case Bearing::north:
        this->bearing_ = Bearing::east;
        break;
      case Bearing::east:
        this->bearing_ = Bearing::south;
        break;
      case Bearing::south:
        this->bearing_ = Bearing::west;
        break;
      case Bearing::west:
        this->bearing_ = Bearing::north;
        break;
    }
  }
  
  void advance() noexcept {
    switch (this->bearing_) {
      case Bearing::north:
        this->position_.second += 1;
        break;
      case Bearing::east:
        this->position_.first += 1;
        break;
      case Bearing::south:
        this->position_.second -= 1;
        break;
      case Bearing::west:
        this->position_.first -= 1;
        break;
    }
  }
  
  void execute_sequence(const std::string_view seq) noexcept {
    for (const auto c: seq) {
      switch (c) {
        case 'L':
          this->turn_left();
          break;
        case 'R':
          this->turn_right();
          break;
        case 'A':
          this->advance();
          break;
        default:
          // do_nothing();
          break;
      }
    }
  }
  
public: // getters
  auto get_bearing() const noexcept {
    return this->bearing_;
  }
    
  auto get_position() const noexcept {
    return this->position_;
  }
    
};

} // namspace robot_simulator

#endif
