/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include "bracket_push.h"

bool bracket_push::check(const std::string& str)
{
  std::string symbols;
  
  for (const auto c: str) {
    switch (c) {
      case '(': case '{': case '[':
        symbols += c;
        break;
        
      case ')':
        // Calling `back()` on an empty container is undefined.
        if (!symbols.empty() && symbols.back() == '(') {
          symbols.pop_back();
          break;
        } 
        return false;
      case ']':
        if (!symbols.empty() && symbols.back() == '[') {
          symbols.pop_back();
          break;
        }
        return false;
      case '}':
        if (!symbols.empty() && symbols.back() == '{') {
          symbols.pop_back();
          break;
        }
        return false;
        
      default:
        break;
    }
  }
  
  return symbols.empty(); 
}