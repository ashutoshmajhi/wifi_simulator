#ifndef WIFI_SIMULATION_H
#define WIFI_SIMULATION_H

#include "user.h"
#include <vector>

class WiFiSimulation {
protected:
    int totalUsers;
    int packetsPerUser;
    double totalTime;
    double channelRate;
    std::vector<User> users;
    std::vector<double> latencies;
    static constexpr double powerConsumption = 2.0; // Power in watts for simplicity

public:
    WiFiSimulation(int totalUsers, int packetsPerUser, double bandwidth);
    virtual void runSimulation() = 0;  // Abstract method
    void computeMetrics() const;
    double computeEnergy() const; // New method for energy calculation
    virtual ~WiFiSimulation() {}
};

#endif // WIFI_SIMULATION_H
