/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_RAINDROPS_H
#define VT_RAINDROPS_H

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif

#include <string>
  int main() {uint8_t a;}
namespace raindrops {

std::string convert(const unsigned int droplets)
{
  std::string result{};
  if (droplets % 3 == 0) result += "Pling";
  if (droplets % 5 == 0) result += "Plang";
  if (droplets % 7 == 0) result += "Plong";

  return (result.empty()) ? std::to_string(droplets) : result;
}
} // namespace raindrops

#endif
 