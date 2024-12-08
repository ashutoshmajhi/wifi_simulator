#include "wifi4.h"
#include "wifi5.h"
#include "wifi6.h"
#include <iostream>
using namespace std;

void runSimulation(int simulationType, int users, int packetsPerUser, double bandwidth, int maxBackoff, int subChannels) {
    WiFiSimulation* simulation = nullptr;

    switch (simulationType) {
        case 1: 
            cout << "Running WiFi 4 Simulation...\n";
            simulation = new WiFi4(users, packetsPerUser, bandwidth, maxBackoff);
            break;
        case 2: 
            cout << "Running WiFi 5 Simulation...\n";
            simulation = new WiFi5(users, packetsPerUser, bandwidth);
            break;
        case 3: 
            cout << "Running WiFi 6 Simulation...\n";
            simulation = new WiFi6(users, packetsPerUser, bandwidth, subChannels);
            break;
        default:
            cout << "Invalid selection.\n";
            return;
    }

    simulation->runSimulation();
    simulation->computeMetrics();
    cout << "Energy Consumed: " << simulation->computeEnergy() << " Joules\n";
    delete simulation;
}

int main() {
    int simulationType;
    cout << "Select Simulation Type:\n";
    cout << "1. WiFi 4\n2. WiFi 5\n3. WiFi 6\n";
    cin >> simulationType;

    int users = 1000;  // Example number of users
    int packetsPerUser = 10;
    double bandwidth = 20.0;  // MHz
    int maxBackoff = 10;
    int subChannels = 4;

    runSimulation(simulationType, users, packetsPerUser, bandwidth, maxBackoff, subChannels);

    return 0;
}