#include "IngestionService.h"

bool IngestionService::submit(const Telemetry& packet) {
    if (!validate(packet)) {
        return false;
    }
    queue_.enqueueTelemetry(packet);
    return true;
}

IngestionService::IngestionService(TelemetryQueue& queue)
    : queue_(queue) {}
bool IngestionService::validate(const Telemetry& packet) const {
    if (packet.speed_kph < 0 || packet.speed_kph > 200)
        return false;
    if (packet.battery_pct < 0 || packet.battery_pct > 100)
        return false;
    if (packet.altitude_m < -100 || packet.altitude_m > 10000)
        return false;
    if (packet.gps_lat < -90 || packet.gps_lat > 90)
        return false;
    if (packet.gps_lon < -180 || packet.gps_lon > 180)  
        return false;
    return true;
}
  