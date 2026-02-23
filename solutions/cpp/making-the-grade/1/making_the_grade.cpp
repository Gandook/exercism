#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_scores {};

    for (int i{0}; i < student_scores.size(); ++i) {
        rounded_scores.emplace_back(static_cast<int>(student_scores.at(i)));
    }

    return rounded_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int num{0};

    for (int i{0}; i < student_scores.size(); ++i) {
        if (student_scores.at(i) <= 40) {
            num++;
        }
    }

    return num;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int, 4> thresholds {41, 0, 0, 0};

    for (int i{0}; i < 3; ++i) {
        thresholds.at(i + 1) = thresholds.at(i) + (highest_score - thresholds.at(i) + 1) / (4 - i);
    }

    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking {};

    for (int i{0}; i < student_scores.size(); ++i) {
        ranking.emplace_back(std::to_string(i + 1) + ". " + 
            student_names.at(i) + ": " + 
            std::to_string(student_scores.at(i)));
    }

    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (int i{0}; i < student_scores.size(); ++i) {
        if (student_scores.at(i) == 100) {
            return student_names.at(i);
        }
    }

    return "";
}
