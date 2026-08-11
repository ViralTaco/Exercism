#ifndef SPEEDYWAGON_H
#define SPEEDYWAGON_H

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int stature{};
    std::string location{};
    std::vector<int> data{};
    int activity{}; 
};

int uv_light_heuristic(std::vector<int>* data_array);

bool connection_check(pillar_men_sensor* sensor);
int activity_counter(pillar_men_sensor* sensors, int capacity);

// Restoring alarm_control for TEST_10 and TEST_12
bool alarm_control(pillar_men_sensor* sensor);

// Keeping uv_alarm for TEST_14 and TEST_16
bool uv_alarm(pillar_men_sensor* sensor);

bool century_maze_status(int sensor_data);

}  // namespace speedywagon

#endif