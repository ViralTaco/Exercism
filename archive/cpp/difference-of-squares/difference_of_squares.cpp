/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "difference_of_squares.h"
#include <cmath>

int squares::square_of_sum(int x) noexcept
{
  int sum{x};

  while (x-- > 0)
    sum += x;
  
  return sum * sum;
}

int squares::sum_of_squares(int x) noexcept
{
  int sum{ x * x };
  
  while (x-- > 0)
    sum += x * x;
  
  return sum;
}

int squares::difference(int x) noexcept
{
  return std::fabs(squares::sum_of_squares(x) - squares::square_of_sum(x));
}
