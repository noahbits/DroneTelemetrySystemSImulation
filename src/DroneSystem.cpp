#include "DroneSystem.h"

DroneSystem::DroneSystem(const std::string& filename)
    : telemetryQueue_(),
      ingestionService_(telemetryQueue_),
      producer_(ingestionService_, running_),
      processor_(telemetryQueue_, filename, running_),
      running_(false) {}

void DroneSystem::start() {
    running_ = true;
    producerThread_ = std::thread([this]() { producer_.run(); });
    processorThread_ = std::thread([this]() { processor_.run(); });
}
void DroneSystem::stop() {
    running_ = false;
    if (producerThread_.joinable()) {
        producerThread_.join();
    }
    if (processorThread_.joinable()) {
        processorThread_.join();
    }
}
