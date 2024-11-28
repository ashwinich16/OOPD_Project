#include "WiFi6.h"
#include <iostream>

using namespace std;

void WiFi6::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 6 (OFDMA) with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    int totalPackets = numUsers * 10;
    double throughput = 0;
    double totalLatency = 0;
    int maxLatency = 0;

    vector<int> subChannels = {2, 4, 10};
    int numSubChannels = subChannels.size();

    for (int i = 0; i < totalPackets; ++i) {
        int subChannel = subChannels[i % numSubChannels];
        double subChannelFraction = static_cast<double>(subChannel) / 20.0;
        int transmissionTime = 5;

        throughput += PACKET_SIZE * subChannelFraction / transmissionTime;
        totalLatency += transmissionTime;
        maxLatency = max(maxLatency, transmissionTime);
    }

    cout << "WiFi 6 Results (OFDMA):" << endl;
    cout << "Throughput: " << throughput << " KB/ms" << endl;
    cout << "Average Latency: " << totalLatency / totalPackets << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
