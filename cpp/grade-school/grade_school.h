/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_GRADE_SCHOOL_H
#define VT_GRADE_SCHOOL_H
#define EXERCISM_RUN_ALL_TESTS

#include <map>
#include <string>
#include <vector>

namespace grade_school {
class school {
private:
  using roster_type = std::map<int, std::vector<std::string> >;
  roster_type roster_;
  
public:
  school() = default;
  
  void add(const std::string name, const int grade);
  std::vector<std::string> grade(const int id) const;
  roster_type roster() const;
};

} // namespace grade_school

#endif
