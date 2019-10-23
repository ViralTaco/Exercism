/*
 * Copyright (c) 2019 viraltaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "pascals_triangle.h"


namespace pascals_triangle {

[[nodiscard]] matrix_t<int> generate_rows(unsigned int rows)
{
  if (rows == 0U)
    return {};
  
  matrix_t<int> result_matrix{ {1} };
  
  if (rows > 1U)
    result_matrix.push_back({1, 1});
  
  for (unsigned int i{1U}; i < rows; ++i) {
    std::vector<int> row{1};
    
    auto begin{ result_matrix[ i ].begin() };
    while (begin != result_matrix[ i ].end()){
      row.push_back(*begin + *(begin + 1));
      ++begin;
    }
    
    row.push_back(1);
    result_matrix.push_back(row);
  }
  
  return result_matrix;
}

} // namespace pascals_triangle


