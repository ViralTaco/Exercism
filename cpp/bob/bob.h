/*
 * Copyright (c) 2019 viraltaco_
 * SPDX-License-Identifier: MIT
 * <http://www.opensource.org/licenses/MIT>
 */

#ifndef VT_BOB_H
#define VT_BOB_H

#define EXERCISM_RUN_ALL_TESTS 1

#include <string>

namespace bob {

bool is_loud(const std::string& phrase);
bool is_question(const std::string& phrase);
bool is_wordless(const std::string& phrase);

std::string hey(const std::string& phrase);

} // namespace bob

#endif
