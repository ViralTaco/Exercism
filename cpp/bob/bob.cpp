/*
 * Copyright (c) 2019 viraltaco_
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */

#include "bob.h"

#include <algorithm>
#include <map>

#include <cctype>

namespace bob {
static constexpr char kQuestionToken { '?' };

enum class action : int {
  answer_question
, ask_to_chill
, ignore_manners
, give_no_fucks 
};

static const std::map<action, std::string> kRetort {
  { action::answer_question , "Sure."              }
, { action::give_no_fucks   , "Whatever."          }
, { action::ask_to_chill    , "Whoa, chill out!"   }
, { action::ignore_manners  , "Fine. Be that way!" }
};

std::string hey(const std::string& phrase)
{
  action say { action::give_no_fucks };
  
  if (is_wordless(phrase)) {
    say = action::ignore_manners;
  } else if (is_loud(phrase)) {
    say = action::ask_to_chill;
  } else if (is_question(phrase)) {
    say = action::answer_question;
  }
  
  return kRetort.at(say);
}

bool is_loud(const std::string& phrase)
{
  const auto uppercase_count {
    std::count_if(phrase.begin(), phrase.end(), ::isupper)
  };
  
  const auto lowercase_count {
    std::count_if(phrase.begin(), phrase.end(), ::islower)
  };
  
  return uppercase_count > lowercase_count;
}

bool is_question(const std::string& phrase)
{ 
  const auto last_non_blank_ptr {
    std::find_if_not(phrase.rbegin(), phrase.rend(), ::isblank)
  };
  return *last_non_blank_ptr == kQuestionToken;
}

bool is_wordless(const std::string& phrase)
{ return std::none_of(phrase.begin(), phrase.end(), ::isalnum); }

} // namespace bob
