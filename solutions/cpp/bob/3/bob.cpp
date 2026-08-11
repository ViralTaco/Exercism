/* Copyright (c) 2019, 2026 viraltaco_
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */
#include "bob.h"

#include <algorithm>  // std::{ find_if_not, none_of }
#include <utility>    // std::ignore
#include <cctype>     // std::{ islower, isupper, isalnum, isblank }

auto bob::is_loud(const std::string_view phrase) noexcept -> bool {
  auto uppers = 0z, lowers = 0z;
  
  for (const unsigned char c: phrase) {
    if      (std::islower(c)) std::ignore = ++lowers;
    else if (std::isupper(c)) std::ignore = ++uppers;
  }
  
  return uppers > lowers;
}

auto bob::is_question(const std::string_view phrase) noexcept -> bool {
  static constexpr auto kQuestionToken = '?';
  const auto last_non_blank_it = std::find_if_not(phrase.crbegin(), phrase.crend(),
      [] (unsigned char c) { return std::isblank(c); });
  return *last_non_blank_it == kQuestionToken;
}

auto bob::is_wordless(const std::string_view phrase) noexcept -> bool {
  return std::none_of(phrase.cbegin(), phrase.cend(), [] (unsigned char c) {
    return std::isalnum(c);
  });
}

auto bob::hey(const std::string_view phrase) noexcept -> std::string {
  enum action { answer, chill, ignore, whatever, trust };
  auto say = whatever;
  
  const auto kWordless = is_wordless(phrase);
  const auto kQuestion = is_question(phrase);
  const auto kShouting = is_loud(phrase);
  
  if      (kWordless) say = (kQuestion) ? answer : ignore;
  else if (kShouting) say = (kQuestion) ? trust : chill;
  else if (kQuestion) say = answer;
  
  switch (say) {
  default: [[fallthrough]];
  case whatever: return "Whatever.";
  case trust:    return "Calm down, I know what I'm doing!";
  case ignore:   return "Fine. Be that way!";
  case chill:    return "Whoa, chill out!";
  case answer:   return "Sure.";
  }
}
