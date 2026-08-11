#ifndef VT_SERIES_H
/** Copyright (c) 2019, 2026 ViralTaco_
	* SPDX-License-Identifier: MIT
	* <http://www.opensource.org/licenses/MIT>
	*/
#define VT_SERIES_H "com.viraltaco.series v" "2.0.0"

#include <vector>
#include <string>
#include <string_view>

namespace series {
auto slice(std::string_view num_list, const std::size_t series_length) -> std::vector<std::string>;
}  // namespace series

#endif
