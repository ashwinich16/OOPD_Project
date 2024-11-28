#include "WiFi4.h"

void WiFi4::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 4 with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    int totalPackets = numUsers * 10;
    double totalData = 0, totalTime = 0, totalLatency = 0;
    int maxLatency = 0;

    for (int i = 0; i < totalPackets; ++i) {
        int backoffTime = getBackoffTime(numUsers);
        int transmissionTime = TRANSMISSION_TIME_PER_PACKET + backoffTime;

        totalData += PACKET_SIZE;
        totalTime += transmissionTime;
        totalLatency += transmissionTime;
        maxLatency = max(maxLatency, transmissionTime);
    }

    double throughput = totalData / totalTime;

    cout << "WiFi 4 Results:" << endl;
    cout << "Throughput: " << throughput << " KB/ms" << endl;
    cout << "Average Latency: " << totalLatency / totalPackets << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}

int WiFi4::getBackoffTime(int numUsers) const {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, MAX_BACKOFF_TIME * numUsers);
    return dis(gen);
}
