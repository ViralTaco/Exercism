#include "leap.h"

bool leap::is_leap_year(const int year) noexcept 
{
  return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0;
}
