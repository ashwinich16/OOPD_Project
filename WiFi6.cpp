#include "WiFi6.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void WiFi6::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 6 (OFDMA) with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    const double bandwidth = 20.0;        // Total bandwidth in MHz
    const double spectralEfficiency = 5.0; // bits/Hz for 256-QAM
    const vector<int> subChannels = {2, 4, 10}; // Subchannel sizes in MHz
    const int numPackets = 100;          // Number of packets per user
    const double packetSizeKB = 1.0;     // Size of each packet in KB

    double totalThroughput = 0.0;
    double totalLatency = 0.0;
    int maxLatency = 0;
    vector<double> userLatencies;

    int numSubChannels = subChannels.size();
    int totalActiveBandwidth = 0;
    for (int sc : subChannels) {
        totalActiveBandwidth += sc;
    }
    totalActiveBandwidth = min(totalActiveBandwidth, static_cast<int>(bandwidth));

    for (int t = 0; t < 5; ++t) {
        for (int i = 0; i < numUsers; ++i) {
            int subChannel = subChannels[i % numSubChannels];
            double subChannelFraction = double(subChannel) / bandwidth;

            double userDataRate = subChannelFraction * bandwidth * spectralEfficiency * 1e6;
            double userThroughput = (userDataRate / 8) / 1e3; // Convert to KB/ms

            double userTransmissionTime = (numPackets * packetSizeKB) / userThroughput;

            double userWaitingTime = i * 5.0 / numUsers;
            double userLatency = userWaitingTime + userTransmissionTime;

            userLatencies.push_back(userLatency);
            totalLatency += userLatency;
            maxLatency = max(maxLatency, int(userLatency));

            totalThroughput += userThroughput;
        }
    }
    double averageLatency = totalLatency / numUsers;

    double maxPossibleThroughput = (totalActiveBandwidth * spectralEfficiency * 1e6) / (8 * 1e3); // KB/ms
    totalThroughput = min(totalThroughput, maxPossibleThroughput);

    cout << "WiFi 6 Results (OFDMA):" << endl;
    cout << "Total Throughput: " << totalThroughput << " KB/ms" << endl;
    cout << "Average Latency: " << averageLatency << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
