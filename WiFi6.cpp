#include "WiFi6.h"

#include "WiFi6.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void WiFi6::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 6 (OFDMA) with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    // Constants
    const double bandwidth = 20.0;        // Total bandwidth in MHz
    const double spectralEfficiency = 5.0; // bits/Hz for 256-QAM
    const vector<int> subChannels = {2, 4, 10}; // Subchannel sizes in MHz

    double totalThroughput = 0.0;
    double totalLatency = 0.0;
    int maxLatency = 0;

    int numSubChannels = subChannels.size();
    int totalActiveBandwidth = 0;

    // Calculate the effective bandwidth used
    for (int sc : subChannels) {
        totalActiveBandwidth += sc;
    }
    totalActiveBandwidth = min(totalActiveBandwidth, (int)bandwidth);

    // Allocate users to subchannels (round-robin)
    for (int t = 0; t < 5; ++t) { // 5 ms transmission cycle
        for (int i = 0; i < numUsers; ++i) {
            int subChannel = subChannels[i % numSubChannels];
            double subChannelFraction = static_cast<double>(subChannel) / bandwidth;

            // Data rate for this user
            double userDataRate = subChannelFraction * bandwidth * spectralEfficiency * 1e6; // bits/s
            double userThroughput = (userDataRate / 8) / 1e3; // Convert to KB/ms
            totalThroughput += userThroughput;

            // Latency contribution
            int latency = 5 + static_cast<int>(numUsers / numSubChannels);
            totalLatency += latency;
            maxLatency = max(maxLatency, latency);
        }
    }

    // Average latency
    double averageLatency = totalLatency / (numUsers * 5);

    // Cap throughput based on total bandwidth
    double maxPossibleThroughput = (totalActiveBandwidth * spectralEfficiency * 1e6) / (8 * 1e3); // KB/ms
    totalThroughput = min(totalThroughput, maxPossibleThroughput);

    // Display results
    cout << "WiFi 6 Results (OFDMA):" << endl;
    cout << "Total Throughput: " << totalThroughput << " KB/ms" << endl;
    cout << "Average Latency: " << averageLatency << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
