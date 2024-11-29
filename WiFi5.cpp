#include "WiFi5.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void WiFi5::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 5 with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    // WiFi 5 constants
    const double bandwidth = 20.0;       // Total bandwidth in MHz
    const double spectralEfficiency = 5.0; // bits/Hz for 256-QAM, rate 5/6
    const double efficiency = 0.7;      // 70% efficiency due to protocol overhead

    // Calculate total peak data rate
    double peakDataRate = bandwidth * spectralEfficiency * 1e6 * efficiency; // bits/s
    double totalThroughput = (peakDataRate / 8) / 1e3; // Convert to KB/ms

    // Subtract overhead for broadcast and CSI
    double overheadTime = (1.0 + numUsers * 200.0 / (peakDataRate / 8 / 1e3)); // Broadcast + CSI
    double effectiveCommunicationTime = 15.0 - overheadTime; // Remaining time for data

    // Adjust throughput for effective communication time
    double adjustedThroughput = totalThroughput * (effectiveCommunicationTime / 15.0);

    // Per-user throughput
    double perUserThroughput = adjustedThroughput / numUsers;

    // Latency calculations
    double totalLatency = overheadTime + effectiveCommunicationTime;
    int maxLatency = static_cast<int>(overheadTime + (numUsers - 1) * (15.0 / numUsers));

    // Display results
    cout << "WiFi 5 Results:" << endl;
    cout << "Total Throughput: " << adjustedThroughput << " KB/ms" << endl;
    cout << "Per-User Throughput: " << perUserThroughput << " KB/ms" << endl;
    cout << "Average Latency: " << totalLatency / numUsers << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
