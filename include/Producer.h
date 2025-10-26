#ifndef PRODUCER_H
#define PRODUCER_H

#include "Telemetry.h"
#include "IngestionService.h"
#include <atomic>

class Producer {
public:
    Producer(IngestionService& ingestion_service, std::atomic<bool>& running);
    void run();

private:
    IngestionService& ingestion_service_;
    std::atomic<bool>& running_; // shared stop flag
};

#endif // PRODUCER_H
