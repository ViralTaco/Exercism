#pragma once  /// Copyright 2026 viraltaco_ <https://viraltaco.com>
#ifndef vt_twelve_days_h
#define vt_twelve_days_h "com.viraltaco.twelve_days v" "0.0.1"

#include <array>
#include <cstdint>
#include <string>
#include <string_view>

namespace twelve_days {

using u8 = std::uint_fast8_t;
constexpr auto recite(u8 low, const u8 high) -> std::string {
  // if (low < 1 or high < low or high > 12) return recite(1, 12);
  using std::string_view_literals::operator""sv;
  static constexpr auto kLyrics = std::array<std::string_view, 12>{
      "On the first day of Christmas my true love gave to me: a Partridge in "
      "a Pear Tree.\n"sv,
      "On the second day of Christmas my true love gave to me: two Turtle "
      "Doves, and a Partridge in a Pear Tree.\n"sv,
      "On the third day of Christmas my true love gave to me: three French "
      "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"sv,
      "On the fourth day of Christmas my true love gave to me: four Calling "
      "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
      "Tree.\n"sv,
      "On the fifth day of Christmas my true love gave to me: five Gold "
      "Rings, four Calling Birds, three French Hens, two Turtle Doves, and a "
      "Partridge in a Pear Tree.\n"sv,
      "On the sixth day of Christmas my true love gave to me: six "
      "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
      "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"sv,
      "On the seventh day of Christmas my true love gave to me: seven "
      "Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling "
      "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
      "Tree.\n"sv,
      "On the eighth day of Christmas my true love gave to me: eight "
      "Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five "
      "Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, "
      "and a Partridge in a Pear Tree.\n"sv,
      "On the ninth day of Christmas my true love gave to me: nine Ladies "
      "Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six "
      "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
      "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"sv,
      "On the tenth day of Christmas my true love gave to me: ten "
      "Lords-a-Leaping, nine Ladies Dancing, eight Maids-a-Milking, seven "
      "Swans-a-Swimming, six Geese-a-Laying, five Gold Rings, four Calling "
      "Birds, three French Hens, two Turtle Doves, and a Partridge in a Pear "
      "Tree.\n"sv,
      "On the eleventh day of Christmas my true love gave to me: eleven "
      "Pipers Piping, ten Lords-a-Leaping, nine Ladies Dancing, eight "
      "Maids-a-Milking, seven Swans-a-Swimming, six Geese-a-Laying, five "
      "Gold Rings, four Calling Birds, three French Hens, two Turtle Doves, "
      "and a Partridge in a Pear Tree.\n"sv,
      "On the twelfth day of Christmas my true love gave to me: twelve "
      "Drummers Drumming, eleven Pipers Piping, ten Lords-a-Leaping, nine "
      "Ladies Dancing, eight Maids-a-Milking, seven Swans-a-Swimming, six "
      "Geese-a-Laying, five Gold Rings, four Calling Birds, three French "
      "Hens, two Turtle Doves, and a Partridge in a Pear Tree.\n"sv
  };
  
  auto ret = std::string{ kLyrics[low - 1u] };
  
  for (; low != high; ++low) {
    ret.append("\n")
       .append(kLyrics[low])
       ;
  }
  
  return ret;
}
}  // namespace twelve_days

#endif  // ndef vt_twelve_days_h
