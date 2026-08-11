/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_ROBOT_NAME_H
#define VT_ROBOT_NAME_H

#define EXERCISM_RUN_ALL_TESTS // ¯\_(ツ)_/¯

#include <string>
#include <vector>
#include <random>
#include <algorithm>

namespace robot_name {
class robot {
private:
  std::string name_;
  
public:
  std::vector<std::string> used_; // used names not to be reused. 

  robot() : name_{}
  { reset(); }
  
  void reset()
  {
    do {
      name_.clear();
      
      std::random_device rd;
      std::mt19937_64 gen(rd());
      std::uniform_int_distribution<> num_distro(0, 9);
      std::uniform_int_distribution<> let_distro(0, 25);
      
      for (int i{0}; i < 2; ++i)
        name_ += 'A' + let_distro(gen);
      
      for (int i{0}; i < 3; ++i)
        name_ += '0' + num_distro(gen);
      
    } while (std::find(used_.begin(), used_.end(), name_) != used_.end());
    
    robot::used_.push_back(name_);
  }
  
  std::string name() const noexcept
  { return name_; }
};

} // namespace robot_name

#endif
