#include "WiFi5.h"
#include <iostream>

using namespace std;

void WiFi5::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 5 with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    double throughput = 0;
    double totalLatency = 0;
    int maxLatency = 0;

    int csiPacketSize = 200;
    int broadcastPacketSize = PACKET_SIZE;

    int broadcastTransmissionTime = broadcastPacketSize / 2;
    throughput += broadcastPacketSize / broadcastTransmissionTime;
    totalLatency += broadcastTransmissionTime;
    maxLatency = max(maxLatency, broadcastTransmissionTime);

    for (int i = 0; i < numUsers; ++i) {
        int csiTransmissionTime = csiPacketSize / 2;
        throughput += csiPacketSize / csiTransmissionTime;
        totalLatency += csiTransmissionTime;
        maxLatency = max(maxLatency, csiTransmissionTime);
    }

    int parallelCommunicationTime = 15;
    throughput += numUsers * csiPacketSize / parallelCommunicationTime;
    totalLatency += parallelCommunicationTime;
    maxLatency = max(maxLatency, parallelCommunicationTime);

    cout << "Throughput: " << throughput << " KB/ms" << endl;
    cout << "Average Latency: " << totalLatency / (numUsers + 1) << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
