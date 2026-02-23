#pragma once

#include <string>

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
    public:
        std::string name{};
        int generation{1};
        int busters{0};
        star_map::System current_system{};
        
        Vessel(const std::string& name, const int generation, const star_map::System& current_system = star_map::System::Sol);
        Vessel replicate(const std::string& name);
        void make_buster();
        bool shoot_buster();
    };

    std::string get_older_bob(const Vessel& vessel1, const Vessel& vessel2);
    bool in_the_same_system(const Vessel& vessel1, const Vessel& vessel2);
}
