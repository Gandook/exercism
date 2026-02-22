#pragma once

#include <string>
#include <memory>

namespace troy {
    struct artifact {
        // constructors needed (until C++20)
        artifact(std::string name) : name(name) {}
        std::string name;
    };
    
    struct power {
        // constructors needed (until C++20)
        power(std::string effect) : effect(effect) {}
        std::string effect;
    };

    struct human {
        std::unique_ptr<artifact> possession{nullptr};
        std::shared_ptr<power> own_power{nullptr};
        std::shared_ptr<power> influenced_by{nullptr};
    };

    void give_new_artifact(human& person, const std::string& artifact_name);
    void exchange_artifacts(std::unique_ptr<artifact>& possession1, std::unique_ptr<artifact>& possession2);
    void manifest_power(human& person, const std::string& power_name);
    void use_power(const human& caster, human& target);
    int power_intensity(const human& person);
}  // namespace troy
