#ifndef DRONESYSTEM_H
#define DRONESYSTEM_H

#include "Telemetry.h"
#include "TelemetryQueue.h"
#include "IngestionService.h"
#include "Producer.h"
#include "Processor.h"
#include <thread>
#include <atomic>
#include <fstream>

/**
 * @brief Top-level class that manages the telemetry system lifecycle.
 * Owns all major components (Producer, IngestionService, Queue, Processor)
 * and manages their threads and startup/shutdown.
 */

class DroneSystem {
public:
    DroneSystem(const std::string& filename = "telemetry.jsonl");
    void start();  // starts the producer and processor
    void stop();   // stops the producer and processor
private:
    TelemetryQueue telemetryQueue_;
    IngestionService ingestionService_;
    Producer producer_;
    Processor processor_;
    std::thread producerThread_;
    std::thread processorThread_;
    std::atomic<bool> running_{false};

};

#endif // DRONESYSTEM_H