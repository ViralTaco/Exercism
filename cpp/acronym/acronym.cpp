#include "acronym.h"
#include <cctype>

std::string acronym::acronym(const std::string& str)
{
  const size_t len{ str.length() };
  if (len == 0)
    return str;
  std::string result{ static_cast<char>(std::toupper(str[0])) };

  for (unsigned i{1}; i + 1 < len; ++i) {
    if (!std::isalpha(str[i]) && std::isalpha(str[i + 1]))
      result += std::toupper(str[i + 1]);
  }
  
  return result;
}
