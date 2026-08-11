#include <string>
#include <vector>

namespace election {

struct ElectionResult {
    std::string name{};
    int votes{};
};

// Task 1: Return the current vote count
int vote_count(const ElectionResult& result) {
    return result.votes;
}

// Task 2: Increment the vote count by a given amount
void increment_vote_count(ElectionResult& result, int votes) {
    result.votes += votes;
}

// Task 3: Determine the winner, prefix their name, and return a reference
ElectionResult& determine_result(std::vector<ElectionResult>& final_count) {
    size_t winner_index = 0;
    
    for (size_t i = 1; i < final_count.size(); ++i) {
        if (final_count[i].votes > final_count[winner_index].votes) {
            winner_index = i;
        }
    }
    
    ElectionResult& winner = final_count[winner_index];
    winner.name = "President " + winner.name;
    
    return winner;
}

}  // namespace election