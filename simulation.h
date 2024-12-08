#ifndef SIMULATION_LOGGER_H
#define SIMULATION_LOGGER_H

#include <vector>
#include <string>

class SimulationLogger {
public:
    static void logResultsToFile(const std::string& filename, const std::vector<int>& userCounts,
                                  const std::vector<double>& throughputs, const std::vector<double>& latencies);
};

#endif // SIMULATION_LOGGER_H
