#pragma once /// Copyright 2026 viraltaco_ <https://anth.pro>
#ifndef vt_yacht_h
#define vt_yacht_h "com.viraltaco.yacht v" "0.0.1"

#include <string_view>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <array>

namespace yacht {
namespace /*(anonymous)*/ {
  class category {
    static constexpr auto kOnes            = std::string_view { "ones" };
    static constexpr auto kTwos            = std::string_view { "twos" };
    static constexpr auto kThrees          = std::string_view { "threes" };
    static constexpr auto kFours           = std::string_view { "fours" };
    static constexpr auto kFives           = std::string_view { "fives" };
    static constexpr auto kSixes           = std::string_view { "sixes" };
    static constexpr auto kFullHouse       = std::string_view { "full house" };
    static constexpr auto kFourOfAKind     = std::string_view { "four of a kind" };
    static constexpr auto kLittleStraight  = std::string_view { "little straight" };
    static constexpr auto kBigStraight     = std::string_view { "big straight" };
    static constexpr auto kChoice          = std::string_view { "choice" };
    static constexpr auto kYacht           = std::string_view { "yacht" };

    enum scores: char {
      Ones = 1
    , Twos = 2
    , Threes = 3
    , Fours = 4
    , Fives = 5
    , Sixes = 6
    , FullHouse
    , FourOfAKind
    , LittleStraight = 30
    , BigStraight
    , Choice
    , Yacht = 50
    , INVALID
    };
    
  public:
    scores score;
    constexpr category(const std::string_view self) noexcept
      : score([](auto s) {
          if (s == kOnes)           return scores::Ones;
          if (s == kTwos)           return scores::Twos;
          if (s == kThrees)         return scores::Threes;
          if (s == kFours)          return scores::Fours;
          if (s == kFives)          return scores::Fives;
          if (s == kSixes)          return scores::Sixes;
          if (s == kFullHouse)      return scores::FullHouse;
          if (s == kFourOfAKind)    return scores::FourOfAKind;
          if (s == kLittleStraight) return scores::LittleStraight;
          if (s == kBigStraight)    return scores::BigStraight;
          if (s == kChoice)         return scores::Choice;
          if (s == kYacht)          return scores::Yacht;
          return scores::INVALID;
        }(self)
      )
    {}
    
    constexpr auto operator()(std::array<int, 5> dices) const noexcept -> int {
      const auto kValue = static_cast<int> (score);
      
      std::sort(dices.begin(), dices.end());
      const auto count_if = [&dices] (auto&& predicate) {
        return std::count_if(dices.cbegin(), dices.cend(), predicate);
      };
      const auto consecutive = [&dices](auto from) {
        if (dices[0] != from) return false;
        for (int const* it = std::next(dices.cbegin()); it != dices.cend(); it = std::next(it)) {
          if (*std::prev(it) + 1 != *it) return false;
        }
        return true;
      };
      
      switch (score) {
        using enum scores;
      case Ones:  case Twos: case Threes:
      case Fours: case Fives: case Sixes: {
        return count_if([&kValue] (auto d) { return d == kValue; }) * kValue;
      }
      case FullHouse: {
        auto [min, max] = std::minmax_element(dices.begin(), dices.end());
        auto kMinCount = count_if([k=*min](auto d) { return k == d; });
        auto kMaxCount = count_if([k=*max](auto d) { return k == d; });
        if (std::max(kMinCount, kMaxCount) != 3) return 0;
        return kMinCount * *min + kMaxCount * *max;
      }
      case FourOfAKind: {
        const auto kMid = dices[2];
        const auto kMatches= count_if([&kMid] (auto d) { return d == kMid; });
        return static_cast<int> (kMatches >= 4) * kMid * 4;
      }
      case LittleStraight:
        return (consecutive(1)) ? kValue : 0;
      case BigStraight:
        return (consecutive(2)) ? static_cast<int> (LittleStraight) : 0;
      case Choice:
        return std::reduce(dices.cbegin(), dices.cend(), 0);
      case Yacht:
        return std::all_of(dices.cbegin(), dices.cend(), [k=dices[0]] (auto d) { return d == k; })
             * kValue
             ;
      case INVALID:
        [[fallthrough]];
      default:
        break;
      }
      return {};
    }
  };
} // namespace (anonymous)
  static constexpr auto score(std::array<int, 5> dices, const std::string_view type)
  noexcept -> int  {
    return category(type)(dices);
  }
} // namespace yacht

#endif //ndef vt_yacht_h
