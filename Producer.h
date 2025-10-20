#ifndef PRODUCER_H
#define PRODUCER_H

#include "Telemetry.h"
#include "IngestionService.h"

/**
 * @brief Simulates a drone telemetry producer.
 * Generates telemetry packets at a fixed rate and submits them to the IngestionService.
 */
class Producer {
public:
    explicit Producer(IngestionService& ingestion_service);
    void run();  // produces and submits telemetry at 1 Hz

private:
    IngestionService& ingestion_service_;
};

#endif // PRODUCER_H
