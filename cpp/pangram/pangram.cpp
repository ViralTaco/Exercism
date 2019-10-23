#include "pangram.h"
#include <cctype> // std::isalpha(); std::tolower();

bool pangram::is_pangram(const std::string& str)
{
  bool seen[26]{false}; 
  
  for (const auto c: str)
    if (std::isalpha(c)) seen[std::tolower(c) - 'a'] = true;
  
  for (const bool b: seen)
    if (!b) return false;
  
  return true; 
}
