#ifndef USER_H
#define USER_H

#include <random>

class User {
private:
    //int id;                // User identifier (may be useful for tracking users)
    //int backoffLimit;      // Maximum backoff time (not used currently)
    double latency;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> backoffDistribution;

public:
    User(int userId, int maxBackoff); // Updated parameter names for clarity
    double transmitPacket(double channelRate, bool& channelFree);
    double getLatency() const;
    void resetLatency();
};

#endif // USER_H
