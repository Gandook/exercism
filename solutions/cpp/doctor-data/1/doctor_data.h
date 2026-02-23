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
    star_map::System current_system{star_map::System::Sol};
    
    Vessel(std::string name, int generation);
    Vessel(std::string name, int generation, star_map::System current_system);
    Vessel replicate(std::string name);
    void make_buster();
    bool shoot_buster();
    };

    std::string get_older_bob(Vessel vessel1, Vessel vessel2);
    bool in_the_same_system(Vessel vessel1, Vessel vessel2);
}
