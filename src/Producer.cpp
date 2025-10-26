#include "Producer.h"
#include <thread>
#include <chrono>
#include <cstdlib>

Producer::Producer(IngestionService& ingestion_service, std::atomic<bool>& running)
    : ingestion_service_(ingestion_service), running_(running) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Producer::run() {
    while (running_) { // check flag each loop
        Telemetry packet;
        packet.drone_id = "DRONE_001";
        packet.timestamp = std::chrono::system_clock::now();
        packet.speed_kph = std::rand() % 201;
        packet.battery_pct = std::rand() % 101;
        packet.altitude_m = (std::rand() % 10100) - 100;
        packet.gps_lat = (std::rand() % 181) - 90;
        packet.gps_lon = (std::rand() % 361) - 180;

        ingestion_service_.submit(packet);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

