#include "wifi4.h"
#include <iostream>

WiFi4::WiFi4(int totalUsers, int packetsPerUser, double bandwidth, int maxBackoff)
    : WiFiSimulation(totalUsers, packetsPerUser, bandwidth), channelFree(true) {     //, maxBackoff(maxBackoff)
    for (int i = 0; i < totalUsers; i++) {
        users.emplace_back(i, maxBackoff);
    }
}

void WiFi4::runSimulation() {
    for (int p = 0; p < packetsPerUser; p++) {
        for (auto& user : users) {
            totalTime += user.transmitPacket(channelRate, channelFree);
            channelFree = true;  // Release channel after each transmission
        }
    }

    for (const auto& user : users) {
        latencies.push_back(user.getLatency());
    }
}
