/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "grade_school.h" // string, map, vector, roster_type
#include <algorithm> // std::sort()

namespace grade_school {
void school::add(const std::string name, const int grade)
{
  if (roster_.find(grade) == roster_.end()) {
    roster_.insert({grade, { std::move(name) } });
  } else {
    roster_[grade].push_back(name);
    std::sort(roster_[grade].begin(), roster_[grade].end());
  }
}

school::roster_type school::roster() const
{
  return roster_;
}

std::vector<std::string> school::grade(const int id) const
{
  if (roster_.find(id) == roster_.end())
    return {};
  
  return roster_.at(id);
}

} // namespace grade_school
