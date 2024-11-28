#include "WiFi6.h"

void WiFi6::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 6 (OFDMA) with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    vector<int> subChannels = {2, 4, 10};
    double totalBandwidth = 20.0, totalThroughput = 0, totalLatency = 0;
    int maxLatency = 0;

    for (int i = 0; i < numUsers * 10; ++i) {
        int subChannel = subChannels[i % subChannels.size()];
        double throughputFraction = double(subChannel) / totalBandwidth;

        totalThroughput += throughputFraction * PACKET_SIZE;
        int currentLatency = 5 + int((numUsers / 10.0));
        totalLatency += currentLatency;
        maxLatency = max(maxLatency, currentLatency);
    }

    cout << "WiFi 6 Results:" << endl;
    cout << "Throughput: " << totalThroughput << " KB/ms" << endl;
    cout << "Average Latency: " << totalLatency / (numUsers * 10) << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
