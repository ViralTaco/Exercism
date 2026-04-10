#include "acronym.h" // std::{ string, string_view }
#include <cctype>    // std::{ toupper, isalpha }
#include <numeric>   // std::accumulate

namespace acronym {
inline namespace string_utils {
template <class CharT> static auto uppercased(const CharT letter) noexcept -> CharT {
  return std::toupper(static_cast<unsigned char> (letter));
}
static auto is_word_boundary(const unsigned char l, const unsigned char r) noexcept -> bool {
  return (not std::isalpha(l) and l != '\'') and std::isalpha(r);
}
} // inline namespace string_utils

auto acronym(std::string_view line) -> std::string {
  const auto on_boundary = [last = '\0'] (std::string acc, auto next) mutable {
    if (is_word_boundary(last, next)) { acc.push_back(uppercased(next)); }
    last = next;
    return acc;
  };

  return std::accumulate(line.begin(), line.end(), std::string(), on_boundary);
}
} // namespace acronym 
