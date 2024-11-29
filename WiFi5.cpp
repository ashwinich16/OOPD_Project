#include "WiFi5.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void WiFi5::simulate(int numUsers, int numAPs) {
    cout << "Simulating WiFi 5 with " << numUsers << " users and " << numAPs << " AP(s)." << endl;
    
    const double bandwidth = 20.0;        // Total bandwidth in MHz
    const double spectralEfficiency = 6.67; // bits/Hz for 256-QAM, rate 5/6
    const double efficiency = 0.7;       // 70% efficiency due to protocol overhead
    const int numPackets = 100;          // Number of packets to be sent by each user
    const double packetSizeKB = 1.0;     // Assumed size of each packet in KB

    double peakDataRate = bandwidth * spectralEfficiency * 1e6 * efficiency;
    double totalThroughput = (peakDataRate / 8) / 1e3; // Convert to KB/ms
    
    double overheadTime = (1.0 + numUsers * 200.0 / (peakDataRate / 8 / 1e3));
    double effectiveCommunicationTime = 15.0 - overheadTime;

    double adjustedThroughput = totalThroughput * (effectiveCommunicationTime / 15.0);

    double timePerPacket = packetSizeKB / adjustedThroughput; 
    double totalPacketTime = timePerPacket * numPackets; 

    double perUserThroughput = (numPackets * packetSizeKB) / totalPacketTime;

    double totalLatency = overheadTime + totalPacketTime; 
    int maxLatency = static_cast<int>(overheadTime + (numUsers - 1) * (15.0 / numUsers));
    
    cout << "WiFi 5 Results:" << endl;
    cout << "Total Throughput: " << adjustedThroughput << " KB/ms" << endl;
    cout << "Per-User Throughput: " << perUserThroughput << " KB/ms" << endl;
    cout << "Average Latency: " << totalLatency / numUsers << " ms" << endl;
    cout << "Maximum Latency: " << maxLatency << " ms" << endl;
}
