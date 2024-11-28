#include "WiFi4.h"
#include <iostream>

using namespace std;

void WiFi4::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 4 with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    int totalPackets = numUsers * 10;  // Simulating 10 packets per user
    double totalData = 0;              // Total data successfully transmitted (in KB)
    double totalTime = 0;              // Total simulation time (in ms)
    double totalLatency = 0;           // Cumulative latency (in ms)
    int maxLatency = 0;                // Maximum latency observed (in ms)

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
