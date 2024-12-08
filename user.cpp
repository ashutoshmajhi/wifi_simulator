#include "user.h"

User::User(int userId, int maxBackoff)
    //: id(userId), backoffLimit(maxBackoff)
    : latency(0.0),
      generator(std::random_device{}()), backoffDistribution(0, maxBackoff) {}

double User::transmitPacket(double channelRate, bool& channelFree) {
    if (channelFree) {
        channelFree = false; // Occupy the channel
        double transmissionTime = 1024.0 * 8 / channelRate; // 1 KB packet in seconds
        latency += transmissionTime;
        return transmissionTime;
    } else {
        // Simulate backoff behavior using `backoffLimit`
        int backoffTime = backoffDistribution(generator);
        latency += backoffTime;
        return backoffTime;
    }
}

double User::getLatency() const {
    return latency;
}

void User::resetLatency() {
    latency = 0.0;
}
