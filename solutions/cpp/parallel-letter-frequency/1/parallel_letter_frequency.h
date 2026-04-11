#pragma once /// Copyright 2026 viraltaco_ <https://viraltaco.com>
#ifndef vt_parallel_letter_frequency
#define vt_parallel_letter_frequency "com.viraltaco.letter-frequency v" "0.1.0"

#include <array>       // std::array
#include <vector>      // std::vector
#include <string_view> // std::string_view
#include <stdexcept>   // std::out_of_range
#include <numeric>     // std::transform_reduce

#ifndef __APPLE__
#  include <execution>
#  define PAR_UNSEQ std::execution::par_unseq,
#else
#  define PAR_UNSEQ 
#endif


namespace parallel_letter_frequency {
 struct frequency {
 public: 
  using string_view = typename std::string_view;
  using record_type = typename std::vector<string_view>;
  using key_type    = typename string_view::value_type;
  using count_type  = unsigned;
 
 private:
  class frequency_map {
  private:
    static constexpr auto kAlphabetSize = 1zu + 'z' - 'a';
    using self_type = typename std::vector<count_type>;
    using node_type = typename self_type::reference;
    using size_type = typename self_type::size_type;

    self_type self;
    bool zero = true;

    static constexpr auto upper = [] (auto c) noexcept { return 'A' <= c and c <= 'Z'; };
    static constexpr auto lower = [] (auto c) noexcept { return 'a' <= c and c <= 'z'; };
    static constexpr auto alpha = [] (auto c) noexcept { return lower(c) or  upper(c); };
    
    /// P: c is an ascii letter.
    /// R: The lexographic index (starting from 0 for 'a', ignoring case).
    [[nodiscard]] static constexpr auto index_for(const auto c) noexcept -> size_type {
      return static_cast<size_type> (c - (upper(c) ? 'A' : 'a'));
    }

  public:
    constexpr frequency_map() noexcept = default;
    constexpr frequency_map(const string_view str) noexcept
      : self()
    { this->insert(str); }

    constexpr auto insert(const string_view str) noexcept -> void {
      for (const auto k: str) {
        if (not alpha(k)) continue; // Not a letter skip
        else if (zero) zero = false;
        ++self[index_for(k)];
      }
    }

    /// P: k is a valid key.
    /// R: the frequency value for the key.
    constexpr auto operator [](const key_type k) const {
      return self[index_for(k)];
    }
    
    constexpr auto empty() const noexcept -> bool {
      return zero;
    }
  };

  frequency_map self;
 public:
  constexpr frequency(record_type const& rec) 
    : self() 
  {
    std::reduce(PAR_UNSEQ       // Execution policy
      rec.cbegin()              // From
    , rec.cend()                // To
    , self                      // Into
    , [] (auto map, auto str) { // Using
      map.insert(str);
      return map;
    });
  }
  
  constexpr auto empty() const noexcept -> bool { return self.empty(); }
  constexpr auto operator [](const key_type k) const { return self[k]; }
 };
}

#endif // ndef vt_parallel_letter_frequency
