#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Telemetry.h"
#include "TelemetryQueue.h"
#include <atomic>
#include <fstream>

class Processor {
public:
    Processor(TelemetryQueue& queue, const std::string& filename, std::atomic<bool>& running);
    void run();

private:
    void writeToFile(const Telemetry& packet);

    TelemetryQueue& queue_;
    std::ofstream outputFile_;
    std::atomic<bool>& running_; // shared stop flag
};

#endif // PROCESSOR_H
