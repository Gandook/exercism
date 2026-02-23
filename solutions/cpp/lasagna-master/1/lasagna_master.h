#pragma once

#include <vector>
#include <string>

namespace lasagna_master {
    struct amount {
        int noodles;
        double sauce;
    };

    int preparationTime(const std::vector<std::string>& layers, const int time = 2);
    amount quantities(const std::vector<std::string>& layers);
    void addSecretIngredient(std::vector<std::string>& mine, const std::vector<std::string>& his);
    void addSecretIngredient(std::vector<std::string>& mine, const std::string& secret);
    std::vector<double> scaleRecipe(std::vector<double> amounts, const int portions);
}  // namespace lasagna_master
