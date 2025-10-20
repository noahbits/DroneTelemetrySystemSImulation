#ifndef TELEMETRY_QUEUE_H
#define TELEMETRY_QUEUE_H
#include "Telemetry.h"
#include <queue>
#include <mutex>


class TelemetryQueue {
public:
    TelemetryQueue() = default;
    ~TelemetryQueue() = default;

    void enqueueTelemetry(const Telemetry& packet);
    bool dequeueTelemetry(Telemetry& packet);

    size_t getQueueSize() const;
private:
    std::queue<Telemetry> telemetryQueue;
    mutable std::mutex queueMutex;
};

#endif // TELEMETRY_QUEUE_H

