/*
 * Copyright (c) 2019 viraltaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "pascals_triangle.h"

namespace pascals_triangle {
Matrix<int> generate_rows(const int rows) {
  if (rows == 0)
    return {};
  
  Matrix<int> result_matrix{};
  for (int x = 1; x <= rows; ++x) {
    std::vector<int> line{ 1 }; // First elem is always 1
    int coef = 1;
    
    for (int y = 1; y < x; ++y) {
      coef = coef * (x - y) / y;
      line.push_back(coef);
    }
    
    result_matrix.push_back(line);
  }
  
  return result_matrix;
}

} // namespace pascals_triangle


