#ifndef WIFI4_H
#define WIFI4_H

#include "wifi_simulation.h"

class WiFi4 : public WiFiSimulation {
private:
    //int maxBackoff;  // Determines maximum backoff time for user retransmissions (not yet used)
    bool channelFree;

    // Constants
    static constexpr double packetSize = 1024;                  // 1 KB packet size (in bytes)
    static constexpr double parallelTransmissionTime = 0.000005; // Parallel transmission time (in seconds)

public:
    WiFi4(int totalUsers, int packetsPerUser, double bandwidth, int maxBackoff);
    void runSimulation() override;

    // Accessor for constants (optional, for external use if needed)
    static double getPacketSize() { return packetSize; }
    static double getParallelTransmissionTime() { return parallelTransmissionTime; }
};

#endif // WIFI4_H
