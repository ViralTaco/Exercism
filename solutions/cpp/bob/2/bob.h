#ifndef VT_BOB_H
/* Copyright (c) 2019, 2026  viraltaco_
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */
#define VT_BOB_H "com.viraltaco.bob v" "2.0.0"

#include <string>
#include <string_view>

namespace bob {
  auto is_loud(const std::string_view phrase) noexcept -> bool;
  auto is_question(const std::string_view phrase) noexcept -> bool;
  auto is_wordless(const std::string_view phrase) noexcept -> bool;
  
  auto hey(const std::string_view phrase) noexcept -> std::string;
  
} // namespace bob

#endif
