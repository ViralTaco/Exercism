/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_CLOCK_H
#define VT_CLOCK_H

#define EXERCISM_RUN_ALL_TESTS 

#include <string>
#include <sstream>

namespace date_independent {
class clock {
private:
  static constexpr int kDayHours_{ 24 };
  static constexpr int kHourMinutes_{ 60 };

public:
  int hour;  
  int minute;
  
  clock(int h, int m): hour{ h }, minute{ m }
  { regularize(); }
  
  static clock at(int h, int m) // named constructor
  { return clock(h, m); }
  
  void regularize() 
  {
    for (; minute < 0 ; minute += kHourMinutes_) --hour;
    for (; minute > 59; minute -= kHourMinutes_) ++hour;
    
    while (hour < 0 ) hour += kDayHours_;
    while (hour > 23) hour -= kDayHours_;
  }
  
  clock& plus(int mins)
  {
    minute += mins;
    regularize();
    
    return *this;
  }
  
  std::string to_string() const
  {
    std::stringstream result;
    
    if (hour < 10) result << "0";
    result << hour << ":";
    
    if (minute < 10) result << "0";
    result << minute;
    
    return result.str();
  }
  
public: // operator overload
  operator std::string() const
  { return this->to_string(); }

  clock& operator +=(int mins)
  { return this->plus(mins); }

public: // friends :D
  friend bool operator ==(const clock& lhs, const clock& rhs)
  { return lhs.minute == rhs.minute && lhs.hour == rhs.hour; }
  
  friend bool operator !=(const clock& lhs, const clock& rhs)
  { return !(lhs == rhs); }
};
} // namespace date_independent

#endif
