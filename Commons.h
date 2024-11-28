#ifndef COMMONS_H
#define COMMONS_H

#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <cmath>

using namespace std;

const int PACKET_SIZE = 1024;         // 1 KB packet size
const int MAX_BACKOFF_TIME = 10;      // Max backoff time in ms
const int TRANSMISSION_TIME_PER_PACKET = 1;  // Simplified transmission time for 1 KB packet

// Exception class for simulation errors
class SimulationException : public runtime_error {
public:
    explicit SimulationException(const string& message) : runtime_error(message) {}
};

// Abstract base class for Communication model
class Communication {
public:
    virtual void simulate(int numUsers, int numAPs) = 0;  // Pure virtual function
    virtual ~Communication() = default;  // Virtual destructor
};

// Template for generic components (User, AP, Packet, etc.)
template<typename IDType>
class Entity {
public:
    explicit Entity(IDType id) : entityId(id) {}
    IDType getId() const { return entityId; }
private:
    IDType entityId;
};

using User = Entity<int>;    // User entity with integer ID
using AP = Entity<int>;      // Access Point (AP) entity with integer ID

class Packet {
public:
    explicit Packet(int size = PACKET_SIZE) : size(size) {}
    int getSize() const { return size; }
private:
    int size;  // Size of the packet
};

class FrequencyChannel {
public:
    explicit FrequencyChannel(double bandwidth = 20.0) : bandwidth(bandwidth) {}
    double getBandwidth() const { return bandwidth; }
private:
    double bandwidth;
};

#endif
