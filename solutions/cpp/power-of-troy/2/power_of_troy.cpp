#include "power_of_troy.h"

namespace troy {
    void give_new_artifact(human& person, const std::string& artifact_name) {
        person.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(std::unique_ptr<artifact>& possession1, std::unique_ptr<artifact>& possession2) {
        std::swap(possession1, possession2);
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
