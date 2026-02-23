#include <string>

namespace log_line {
std::string message(std::string line) {
    int first_whitespace = line.find(" ");
    
    return line.substr(first_whitespace + 1);
}

std::string log_level(std::string line) {
    int closing_bracket_index = line.find("]");
    int level_length = closing_bracket_index - 1;

    return line.substr(1, level_length);
}

std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
