#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <string>
#include <chrono>

struct Telemetry {
    std::string drone_id;
    double speed_kph;
    double battery_pct;
    double altitude_m;
    double gps_lat;
    double gps_lon;
    std::chrono::system_clock::time_point timestamp;
};

#endif // TELEMETRY_H