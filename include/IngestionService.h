#ifndef INGESTION_SERVICE_H
#define INGESTION_SERVICE_H
#include "Telemetry.h"
#include "TelemetryQueue.h"

class IngestionService {
public:
    explicit IngestionService(TelemetryQueue& queue);
    bool submit(const Telemetry& packet); // called by Producer

private:
    bool validate(const Telemetry& packet) const;
    TelemetryQueue& queue_;
};


#endif // INGESTION_SERVICE_H