/** Copyright (c) 2019, 2026 ViralTaco_
  * SPDX-License-Identifier: MIT
  * <http://www.opensource.org/licenses/MIT>
  */

#include "series.h"
#include <cctype>
#include <stdexcept>

auto series::slice(std::string_view num_list, const std::size_t series_length)
-> std::vector<std::string> {
  if (num_list.empty() or num_list.size() < series_length or series_length == 0) {
    throw std::domain_error("English, Motherfucker, do you speak it?");
  }

  const std::size_t kLen = num_list.size();
  std::vector<std::string> result;
  
  for (std::size_t i{0}; i + series_length <= kLen; ++i)
    result.emplace_back(num_list.substr(i, series_length));

  return result;
}
