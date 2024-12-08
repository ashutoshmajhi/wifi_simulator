#include "wifi5.h"
#include <iostream>

WiFi5::WiFi5(int totalUsers, int packetsPerUser, double bandwidth)
    : WiFiSimulation(totalUsers, packetsPerUser, bandwidth) {
    for (int i = 0; i < totalUsers; i++) {
        users.emplace_back(i, 0);  // No backoff required for WiFi 5
    }
}

void WiFi5::runSimulation() {
    for (int p = 0; p < packetsPerUser; p++) {
        totalTime += 0.001;  // Broadcast phase (1 ms)

        // CSI Phase: Sequential transmission of CSI packets
        // for (const auto& user : users) {
        //     totalTime += (csiPacketSize * 8) / channelRate;
        // }

        // Parallel Transmission Phase: All users transmit in parallel
        totalTime += parallelTransmissionTime;

        for (size_t i = 0; i < users.size(); i++) {
            latencies.push_back(totalTime / packetsPerUser);
        }
    }
}
