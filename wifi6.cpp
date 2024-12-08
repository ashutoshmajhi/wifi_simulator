#include "wifi6.h"
#include <iostream>
#include <cmath>

WiFi6::WiFi6(int totalUsers, int packetsPerUser, double bandwidth, int subChannels)
    : WiFiSimulation(totalUsers, packetsPerUser, bandwidth), subChannels(subChannels) {
    for (int i = 0; i < totalUsers; i++) {
        users.emplace_back(i, 0);
    }
}

void WiFi6::runSimulation() {
    double subChannelBandwidth = (subChannels > 0) ? channelRate / subChannels : channelRate;

    for (int p = 0; p < packetsPerUser; p++) {
        // Round-robin scheduling: Assign users to sub-channels
        for (int ch = 0; ch < subChannels; ch++) {
            for (int u = ch; u < totalUsers; u += subChannels) {
                // Simulate transmission for this user on the sub-channel
                double transmissionTime = packetSize * 8 / subChannelBandwidth;

                // Update total simulation time and latency
                totalTime += transmissionTime;
                latencies.push_back(totalTime);

                // Break if all users have transmitted
                if (u >= totalUsers) break;
            }
        }
        totalTime += transmissionWindow;
    }

    // Handle edge cases for single user
    if (totalUsers == 1) {
        latencies.push_back(totalTime);
    }

    // Example: Output transmission window and packet size
    //std::cout << "Transmission Window: " << transmissionWindow << " seconds,";
    //std::cout << "Packet Size: " << packetSize << " bytes\n";
}
