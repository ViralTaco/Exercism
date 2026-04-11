#pragma once  /// Copyright 2026 viraltaco_ <https://viraltaco.com>
#ifndef vt_parallel_letter_frequency
#define vt_parallel_letter_frequency \
  "com.viraltaco.letter-frequency v" \
  "0.3.0"

#include <array>        // std::array
#include <numeric>      // std::transform_reduce
#include <stdexcept>    // std::out_of_range
#include <string_view>  // std::string_view
#include <utility>      // std::move
#include <vector>       // std::vector

#ifndef __APPLE__
#include <execution>
#define PAR_UNSEQ std::execution::par_unseq,
#else
#define PAR_UNSEQ
#endif

namespace parallel_letter_frequency {
struct frequency {
 public:
  using string_view = typename std::string_view;
  using record_type = typename std::vector<string_view>;
  using key_type = typename string_view::value_type;
  using count_type = unsigned;

 private:
  class frequency_map {
   private:
    static constexpr auto kAlphabetSize = 1zu + 'z' - 'a';
    using self_type = typename std::array<count_type, kAlphabetSize>;
    using node_type = typename self_type::reference;
    using size_type = typename self_type::size_type;

    self_type self;
    bool zero = true;

    static constexpr auto upper = [](auto c) noexcept { return 'A' <= c and c <= 'Z'; };
    static constexpr auto lower = [](auto c) noexcept { return 'a' <= c and c <= 'z'; };
    static constexpr auto alpha = [](auto c) noexcept { return lower(c) or upper(c); };

    /// P: c is an ascii letter.
    /// R: The lexographic index (starting from 0 for 'a', ignoring case).
    [[nodiscard]] static constexpr auto index_for(const auto c) noexcept -> size_type {
      return static_cast<size_type>(c - (upper(c) ? 'A' : 'a'));
    }

   public:
    constexpr frequency_map() noexcept = default;
    constexpr frequency_map(const string_view str) noexcept : self() { this->insert(str); }

    constexpr frequency_map(frequency_map&& map) noexcept = default;
    constexpr frequency_map& operator=(frequency_map&& map) noexcept = default;

    constexpr frequency_map(frequency_map const& map) noexcept : self(map.self), zero(map.zero) {}

    constexpr frequency_map& operator=(frequency_map const& map) noexcept {
      self = map.self;
      zero = map.zero;
      return *this;
    }

    constexpr auto insert(const string_view str) noexcept -> void {
      for (const auto k : str) {
        if (not alpha(k)) continue;  // Not a letter skip
        self[index_for(k)] += 1;
        zero = false;
      }
    }

    /// P: k is a valid key.
    /// R: the frequency value for the key.
    constexpr auto operator[](const key_type k) const { return self.at(index_for(k)); }

    constexpr auto combine(const frequency_map& other) noexcept -> void {
      std::transform(PAR_UNSEQ self.begin(), self.end(), other.self.begin(), self.begin(),
                     std::plus<>{});
      if (not other.zero) zero = false;
    }

    constexpr auto empty() const noexcept -> bool { return zero; }
  };

  frequency_map self;

 public:
  constexpr frequency(record_type const& rec)
      : self(std::transform_reduce(
            PAR_UNSEQ rec.cbegin(), rec.cend(), frequency_map{},
            [](frequency_map a, frequency_map b) {
              a.combine(b);
              return a;
            },
            [](const string_view str) { return frequency_map{str}; })) {}

  constexpr auto empty() const noexcept -> bool { return self.empty(); }
  constexpr auto operator[](const key_type k) const { return self[k]; }
};
}  // namespace parallel_letter_frequency

#endif  // ndef vt_parallel_letter_frequency
