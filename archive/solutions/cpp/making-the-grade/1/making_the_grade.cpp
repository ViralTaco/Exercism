#include <array>
#include <string>
#include <vector>
#include <algorithm>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded;
    for (double score : student_scores) {
        rounded.push_back(static_cast<int>(score));
    }
    return rounded;
}

// Count the number of failing students (score <= 40).
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for (int score : student_scores) {
        if (score <= 40) count++;
    }
    return count;
}

// Create thresholds for D, C, B, and A based on the highest score.
// The range (highest - 40) is split into 4 equal intervals.
std::array<int, 4> letter_grades(int highest_score) {
    int interval = (highest_score - 40) / 4;
    return {41, 41 + interval, 41 + 2 * interval, 41 + 3 * interval};
}

// Organize student ranking into "Rank. Name: Score" strings.
std::vector<std::string> student_ranking(std::vector<int> student_scores, 
                                        std::vector<std::string> student_names) {
    std::vector<std::string> ranking;
    for (size_t i = 0; i < student_scores.size(); ++i) {
        ranking.push_back(std::to_string(i + 1) + ". " + 
                          student_names[i] + ": " + 
                          std::to_string(student_scores[i]));
    }
    return ranking;
}

// Find the first student with a score of 100.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (size_t i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";
}