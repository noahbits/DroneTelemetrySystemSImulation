#include "TelemetryQueue.h"
#include <queue>
#include <mutex>
#include <condition_variable>

void TelemetryQueue::enqueueTelemetry(const Telemetry& packet) {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        telemetryQueue.push(packet);
    }
}

bool TelemetryQueue::dequeueTelemetry(Telemetry& packet) {
    std::lock_guard<std::mutex> lock(queueMutex);
    if (telemetryQueue.empty()) {
        return false;
    }
    packet = telemetryQueue.front();
    telemetryQueue.pop();
    return true;
}

size_t TelemetryQueue::getQueueSize() const {
    std::lock_guard<std::mutex> lock(queueMutex);
    return telemetryQueue.size();
}

