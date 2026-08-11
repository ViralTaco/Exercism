#pragma once

#include <vector>
#include <ranges>
#include <algorithm>

namespace arcade {
  
  class HighScores {
  private:
    std::vector<int> scores;
    
  public:
    explicit HighScores(std::vector<int> initial_scores) 
        : scores(std::move(initial_scores)) {}
    
    std::vector<int> list_scores() const {
      return this->scores;
    }
    
    int latest_score() const noexcept {
      return this->scores.back();
    }
    
    int personal_best() const noexcept {
      static int pb = *std::ranges::max_element(this->scores);
      return pb;
    }
    
    std::vector<int> top_three() const {
      auto temp = this->scores;
      auto target_end = temp.begin() + std::min<size_t>(3, temp.size());
      std::ranges::partial_sort(temp.begin(), target_end, temp.end(), std::greater<>{});
      return std::vector<int>(std::from_range, temp | std::views::take(3));
    }
  };
  
}  // namespace arcade