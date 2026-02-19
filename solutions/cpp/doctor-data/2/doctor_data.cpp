#include "doctor_data.h"

heaven::Vessel::Vessel(const std::string& name, const int generation, const star_map::System& current_system):
    name{name}, generation{generation}, current_system{current_system} {
}

heaven::Vessel heaven::Vessel::replicate(const std::string& name) {
    return Vessel{name, generation + 1, current_system};
}

void heaven::Vessel::make_buster() {
    busters++;
}

bool heaven::Vessel::shoot_buster() {
    if (busters == 0) {
        return false;
    }
    
    busters--;

    return true;
}

std::string heaven::get_older_bob(const Vessel& vessel1, const Vessel& vessel2) {
    if (vessel1.generation < vessel2.generation) {
        return vessel1.name;
    }
    return vessel2.name;
}

bool heaven::in_the_same_system(const Vessel& vessel1, const Vessel& vessel2) {
    return vessel1.current_system == vessel2.current_system;
}
