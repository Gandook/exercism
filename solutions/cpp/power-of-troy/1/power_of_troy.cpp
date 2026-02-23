#include "power_of_troy.h"
#include <optional>

namespace troy {
    void give_new_artifact(human& person, const std::string& artifact_name) {
        person.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(std::unique_ptr<artifact>& possession1, std::unique_ptr<artifact>& possession2) {
        const std::optional<artifact> artifact1{possession1 == nullptr
        ? std::nullopt
        : std::optional<artifact>(*possession1)};
        const std::optional<artifact> artifact2{possession2 == nullptr
        ? std::nullopt
        : std::optional<artifact>(*possession2)};

        possession1 = nullptr;
        possession2 = nullptr;

        possession1 = artifact2 ? std::make_unique<artifact>(*artifact2) : nullptr;
        possession2 = artifact1 ? std::make_unique<artifact>(*artifact1) : nullptr;
    }

    void manifest_power(human& person, const std::string& power_name) {
        person.own_power = std::make_shared<power>(power_name);
    }

    void use_power(const human& caster, human& target) {
        if (caster.own_power == nullptr) {
            return;
        }
        
        target.influenced_by = caster.own_power;
    }

    int power_intensity(const human& person) {
        if (person.own_power == nullptr) {
            return 0;
        }

        return person.own_power.use_count();
    }
}  // namespace troy
