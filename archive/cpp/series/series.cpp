/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "series.h"
#include <cctype>

std::vector<int> series::digits(const std::string& num_list)
{
  std::vector<int> result;
  
  for (const auto c: num_list)
    if (std::isdigit(c))
      result.push_back(c - '0');
      
  return result;
}

std::vector< std::vector<int> > 
series::slice(const std::string& num_list, const std::size_t series_length)
{
  if (num_list.empty()
  || num_list.length() < series_length 
  || series_length == 0) {
    throw std::domain_error("English, Motherfucker, do you speak it?");
  }
  
  const std::size_t len{ num_list.length() };
  std::vector< std::vector<int> > result; 
  
  for (std::size_t i{0}; i + series_length <= len; ++i)
    result.push_back(
      series::digits(num_list.substr(i, series_length))
    );
  
  return result;
}
