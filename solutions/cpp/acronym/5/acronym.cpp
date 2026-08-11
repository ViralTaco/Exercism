#include "acronym.h" // std::{ string, string_view }
#include <cctype>    // std::{ toupper, isalpha }
#include <numeric>   // std::accumulate

namespace acronym {
 auto acronym(std::string_view line) -> std::string {
   return std::accumulate(line.cbegin(), line.cend(), std::string{}, 
     [nw = true] (std::string acc, unsigned char ch) mutable {
       if (nw and std::isalpha(ch)) { acc.push_back(std::toupper(ch)); }
       nw = (ch == ' ' or ch == '-' or ch == '_');
       return acc;
   });
 }
} // namespace acronym 
