#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(ElectionResult& result) {
    return result.votes;
}

// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult& result, int to_add) {
    result.votes += to_add;
}

// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult& determine_result(std::vector<ElectionResult>& results) {
    int highest{-1};
    int index_of_highest{-1};
    
    for (int i{0}; i < results.size(); ++i) {
        if (results.at(i).votes > highest) {
            highest = results.at(i).votes;
            index_of_highest = i;
        }
    }

    results.at(index_of_highest).name = "President " + results.at(index_of_highest).name;

    ElectionResult& president{results.at(index_of_highest)};
    
    return president;
}

}  // namespace election
