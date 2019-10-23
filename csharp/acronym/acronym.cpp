/*
 * Copyright (c) 2019 ViralTaco_
 * SPDX-License-Identifier: MIT 
 * <http://www.opensource.org/licenses/MIT>
 */

#include <iostream>

#include <string>
#include <regex>

#include <algorithm>

#include <cctype>

using std::string;
struct emo_str {
public: 
  
  std::string value;
  
  emo_str(std::string str) 
    : value{ std::move(str) }
  {}

  static std::string to_upper(std::string str)
  {
    for (int i{0}; i < str.length(); ++i)
      str[i] = std::toupper(str[i]);
      
    return str;
  }
  
  emo_str& shout()
  {
    this->value = emo_str::to_upper(this->value);
    return *this;
  }

  emo_str& rephrase(string pattern = "")
  {
    auto matches{ "" };
    for (auto match: Regex.Matches(value, pattern)) {
      matches += match.Value;
    }

    value = matches;
    return *this;
  }

  emo_str& sterilize(char ignore = '\0')
  {
    std::remove_if(this->value.begin(), this->value.end()
    , [&] (char c) { return c == ignore; } 
    );
    
    for (int i = 0; i < value.length(); ++i) {
      if (not std::isalpha(this->value[i])) {
        this->value[i] = ' ';
      }
    }
    return *this;
  }
  
  std::string to_string() const noexcept
  { return this->value; }

public: // op overloads
  operator string() const noexcept
  { return this->to_string(); }
};

int main(int argc, char **argv) 
{
  
}