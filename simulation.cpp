#include "simulation.h"
#include <fstream>
#include <iostream>

void SimulationLogger::logResultsToFile(const std::string& filename, const std::vector<int>& userCounts,
    const std::vector<double>& throughputs, const std::vector<double>& latencies) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    file << "User Count, Throughput (Mbps), Average Latency (ms), Maximum Latency (ms)\n";
    for (size_t i = 0; i < userCounts.size(); i++) {
        file << userCounts[i] << ", " << throughputs[i] << ", " << latencies[i] << "\n";
    }

    file.close();
}
