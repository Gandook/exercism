#include "speedywagon.h"

namespace speedywagon {
    bool connection_check(const pillar_men_sensor* sensor_ptr) {
        return sensor_ptr != nullptr;
    }

    int activity_counter(const pillar_men_sensor* readings, const int len) {
        int sum{0};

        for (int i{0}; i < len; ++i) {
            sum += (readings + i)->activity;
        }

        return sum;
    }

    bool alarm_control(const pillar_men_sensor* ptr) {
        if (!connection_check(ptr)) {
            return false;
        }

        return ptr->activity > 0;
    }

    bool uv_alarm(pillar_men_sensor* ptr) {
        if (!connection_check(ptr)) {
            return false;
        }

        int heuristic{uv_light_heuristic(&(ptr->data))};

        return heuristic > ptr->activity;
    }
    
    int uv_light_heuristic(std::vector<int>* data_array) {
        double avg{};
        for (auto element : *data_array) {
            avg += element;
        }
        avg /= data_array->size();
        int uv_index{};
        for (auto element : *data_array) {
            if (element > avg) ++uv_index;
        }
        return uv_index;
    }
}  // namespace speedywagon
