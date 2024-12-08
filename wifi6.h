#ifndef WIFI6_H
#define WIFI6_H

#include "wifi_simulation.h"

class WiFi6 : public WiFiSimulation {
private:
    int subChannels;

    // Constants
    static constexpr double packetSize = 1024;                  // 1 KB packet size (in bytes)
    static constexpr double transmissionWindow = 0.005;         // 5 ms parallel transmission window

public:
    WiFi6(int totalUsers, int packetsPerUser, double bandwidth, int subChannels);
    void runSimulation() override;

    // Accessors for constants
    // static double getPacketSize() { return packetSize; }
    // static double getTransmissionWindow() { return transmissionWindow; }
};

#endif // WIFI6_H
