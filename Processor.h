#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Telemetry.h"
#include "TelemetryQueue.h"
#include <fstream>

/**
 * @brief Consumes telemetry from the shared queue and writes it to storage.
 */
class Processor {
public:
    explicit Processor(TelemetryQueue& queue, const std::string& filename = "telemetry.jsonl");
    explicit Processor(TelemetryQueue& queue);
    void run();  // continuously reads from queue and writes to file

private:
    void writeToFile(const Telemetry& packet) const;

    TelemetryQueue& queue_;
    std::ofstream outputFile_;
};

#endif // PROCESSOR_H

