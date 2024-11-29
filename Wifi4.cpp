#include "WiFi4.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void WiFi4::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 4 with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

    // Create Users
    vector<User> users;
    for (int i = 0; i < numUsers; ++i) {
        users.emplace_back(i + 1); // Unique ID for each user
    }

    // Create Packets
    Packet packet(PACKET_SIZE); // Default packet size (1 KB)

    // Total packets to be transmitted
    int totalPackets = numUsers * 10;

    // Initialize performance metrics
    double totalData = 0;              // Total data successfully transmitted (KB)
    double totalTime = 0;              // Total simulation time (ms)
    double totalLatency = 0;           // Cumulative latency (ms)
    int maxLatency = 0;                // Maximum latency observed (ms)

    for (int i = 0; i < totalPackets; ++i) {
        // Calculate random backoff time based on the number of users
        int backoffTime = getBackoffTime(numUsers);

        // Calculate transmission time for each packet
        int transmissionTime = TRANSMISSION_TIME_PER_PACKET + backoffTime;

        totalData += packet.getSize(); // Add packet size to total data
        totalTime += transmissionTime;
        totalLatency += transmissionTime;

        // Update maximum latency
        maxLatency = max(maxLatency, transmissionTime);
    }

    // Calculate throughput
    double throughput = totalData / totalTime;

    // Display results
    cout << "WiFi 4 Results:" << endl;
    cout << "Throughput: " << throughput << " KB/ms" << endl;
    cout << "Average Latency: " << totalLatency / totalPackets << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
