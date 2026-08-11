#ifndef VT_HELLO_WORLD_H
#define VT_HELLO_WORLD_H

#include <string>

namespace hello_world {

[[gnu::pure]] constexpr std::string_view hello() noexcept;

} // namespace hello_world

#endif
