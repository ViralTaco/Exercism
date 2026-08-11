/*
* Copyright (c) 2019 viraltaco
* SPDX-License-Identifier: MIT
* <http://www.opensource.org/licenses/MIT>
*/

#pragma once
#include <string>
#include "boost/date_time/gregorian/gregorian_types.hpp"

namespace meetup {
class scheduler {
private:
  std::string date_str_;
public: // constructor
  // Honestly this seems very boring. I'll do it another time. 
  scheduler(std::string date_str, boost::)
    : date_str_{ date_str }
  {}
  
  
};
}  // namespace meetup

