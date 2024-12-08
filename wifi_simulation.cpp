#include "wifi_simulation.h"
#include <iostream>
#include <algorithm>

WiFiSimulation::WiFiSimulation(int totalUsers, int packetsPerUser, double bandwidth)
    : totalUsers(totalUsers), packetsPerUser(packetsPerUser), totalTime(0), 
      channelRate(bandwidth * 1e6 * (256.0 / 8.0) * (5.0 / 6.0)) {}

void WiFiSimulation::computeMetrics() const {
    double totalLatency = 0;
    double maxLatency = 0;

    for (double latency : latencies) {
        totalLatency += latency;
        maxLatency = std::max(maxLatency, latency);
    }

    double avgLatency = totalLatency / latencies.size();
    double throughput = avgLatency > 0 ? 1 / avgLatency : 0;  // Throughput inversely proportional to latency

    std::cout << "Throughput: " << throughput << " Mbps\n";
    std::cout << "Average Latency: " << avgLatency << " ms\n";
    std::cout << "Maximum Latency: " << maxLatency << " ms\n";
}

double WiFiSimulation::computeEnergy() const {
    return totalTime * powerConsumption; // Energy = time * power
}
