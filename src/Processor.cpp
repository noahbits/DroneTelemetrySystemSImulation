#include "Processor.h"
#include <chrono>
#include <thread>

Processor::Processor(TelemetryQueue& queue, const std::string& filename, std::atomic<bool>& running)
    : queue_(queue), outputFile_(filename, std::ios::app), running_(running) {}

void Processor::run() {
    while (running_) {
        Telemetry packet;
        if (queue_.dequeueTelemetry(packet)) {
            writeToFile(packet);
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // small idle delay
        }
    }
}
