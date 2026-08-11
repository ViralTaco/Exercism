#include "pig_latin.h"  // std::string

#include <algorithm>    // std::any_of
#include <array>        // std::array
#include <sstream>      // std::istringstream
#include <string_view>  // std::string_view

namespace /*(anonymous)*/ {
static constexpr auto starts_with_any(auto&& text, const auto of) -> bool {
  return std::any_of(of.begin(), of.end(), [&](auto needle) { return text.starts_with(needle); });
}

static constexpr auto contains_any(const std::string_view of, const char in) {
  return std::any_of(of.begin(), of.end(), [&](char c) { return c == in; });
}

static inline auto translate_word(std::string const& s) noexcept -> std::string {
  using std::string_literals::operator""s;
  using std::string_view_literals::operator""sv;

  static constexpr auto kVowels = "aeiou"sv;

  if (starts_with_any(s, std::array{"xr"sv, "yt"sv}) or starts_with_any(s, kVowels)) {
    return s + "ay"s;
  }

  auto last = '\0';
  auto back = ""s;
  for (auto i = 0z; auto c : s) {
    const auto not_qu = (last != 'q' or c != 'u');
    const auto y_rule = (c == 'y' and i > 0);

    if (y_rule or (not_qu and contains_any(kVowels, c))) {
      return s.substr(i) + back + "ay"s;
    }

    ++i;
    back.push_back(last = c);
  }

  return back + "ay"s;
}
}  // namespace (anonymous)

auto pig_latin::translate(std::string const& s) noexcept -> std::string {
  auto iss = std::istringstream(s);
  auto result = std::string();
  result.reserve(2zu * s.size());

  std::string word;
  if (iss >> word) {
    result += translate_word(word);
    while (iss >> word) result += ' ' + translate_word(word);
  }

  return result;
}