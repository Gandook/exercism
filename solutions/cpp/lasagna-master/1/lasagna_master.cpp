#include "lasagna_master.h"

namespace lasagna_master {
    int preparationTime(const std::vector<std::string>& layers, const int time) {
        return layers.size() * time;
    }

    amount quantities(const std::vector<std::string>& layers) {
        amount needed{0, 0.0};

        for (const auto& layer : layers) {
            if (layer == "noodles") {
                needed.noodles += 50;
            } else if (layer == "sauce") {
                needed.sauce += 0.2;
            }
        }

        return needed;
    }

    void addSecretIngredient(std::vector<std::string>& mine, const std::vector<std::string>& his) {
        mine.pop_back();
        mine.push_back(his.back());
    }

    void addSecretIngredient(std::vector<std::string>& mine, const std::string& secret) {
        mine.pop_back();
        mine.push_back(secret);
    }

    std::vector<double> scaleRecipe(std::vector<double> amounts, const int portions) {
        for (auto& amount : amounts) {
            amount *= portions;
            amount /= 2;
        }

        return amounts;
    }
}  // namespace lasagna_master
