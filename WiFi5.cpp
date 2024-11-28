#include "WiFi5.h"

void WiFi5::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 5 with " << numUsers << " users and " << numAPs << " AP(s)." << endl;

        int totalPackets = numUsers * 10; // Simulating 10 packets per user
        double throughput = 0;
        double totalLatency = 0;
        int maxLatency = 0;

        // Assuming maximum parallel streams are limited by number of users (simplified)
        int maxStreams = min(numUsers, 8); // Limiting to 8 parallel streams (common in WiFi 5)

        try {
            for (int i = 0; i < totalPackets; ++i) {
                int transmissionTime = 15 + (maxStreams * 2);  // 15 ms for MU-MIMO, additional time for parallel users
                throughput += PACKET_SIZE / transmissionTime;
                totalLatency += transmissionTime;
                maxLatency = max(maxLatency, transmissionTime);

                // Decrease throughput and increase latency as users increase
                throughput -= numUsers / 100.0;  // More users = lower throughput
                throughput = max(0.0, throughput);
                totalLatency += numUsers / 10.0;  // More users = higher latency

                // Check if throughput becomes negative
               
            }

            cout << "WiFi 5 Results:" << endl;
            cout << "Throughput: " << throughput << " KB/ms" << endl;
            cout << "Average Latency: " << totalLatency / totalPackets << " ms" << endl;
            cout << "Maximum Latency: " << maxLatency << " ms" << endl;

        } catch (const std::exception &e) {
            cerr << e.what() << endl;
            // Optionally reset throughput or take other corrective actions
            throughput = 0;
        }
}
