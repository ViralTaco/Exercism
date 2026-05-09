#include "speedywagon.h"

namespace speedywagon {

bool connection_check(pillar_men_sensor* sensor) {
    return sensor != nullptr;
}

int activity_counter(pillar_men_sensor* sensors, int capacity) {
    int total_activity{0};
    for (int i = 0; i < capacity; ++i) {
        total_activity += sensors[i].stature;
        total_activity += uv_light_heuristic(&sensors[i].data);
    }
    return total_activity;
}

// alarm_control usually just checks if the connection is lost (nullptr)
bool alarm_control(pillar_men_sensor* sensor) {
    if (sensor == nullptr) {
        return false;
    }

    // Trigger alarm only if there is recorded activity
    return sensor->activity > 0;
}

// uv_alarm checks if the activity exceeds the recorded stature
bool uv_alarm(pillar_men_sensor* sensor) {
// 1. Return false if the sensor pointer is null.
    if (sensor == nullptr) {
        return false;
    }

    // 2. Call uv_light_heuristic passing the address of the data vector.
    // 3. Return true if the heuristic value > sensor->activity level.
    if (uv_light_heuristic(&sensor->data) > sensor->activity) {
        return true;
    }

    return false;
}

bool century_maze_status(int sensor_data) {
    return sensor_data >= 0 && sensor_data <= 100;
}

int uv_light_heuristic(std::vector<int>* data_array) {
    if (data_array == nullptr || data_array->empty()) return 0;
    double avg{0.0};
    for (auto element : *data_array) avg += element;
    avg /= data_array->size();
    int uv_index{0};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon