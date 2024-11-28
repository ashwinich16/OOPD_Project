#ifndef COMMONS_H
#define COMMONS_H

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <stdexcept>
#include <cmath>

using namespace std;

const int PACKET_SIZE = 1024;         // 1 KB packet size
const int MAX_BACKOFF_TIME = 10;      // Max backoff time in ms
const int TRANSMISSION_TIME_PER_PACKET = 1;  // Simplified transmission time for 1 KB packet

// Exception class for simulation errors
class SimulationException : public exception {
public:
    explicit SimulationException(const string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

// Abstract base class for Communication model
class Communication {
public:
    virtual void simulate(int numUsers, int numAPs) = 0;  // Pure virtual function
    virtual ~Communication() = default;  // Virtual destructor
};

// User class represents a device that transmits packets
class User {
public:
    User(int id) : userId(id) {}
    int getId() const { return userId; }
private:
    int userId;
};

// Access Point (AP) class manages multiple users and their communications
class AP {
public:
    AP(int id) : apId(id) {}
    int getId() const { return apId; }
private:
    int apId;
};

// Packet class represents a data packet
class Packet {
public:
    Packet(int size = PACKET_SIZE) : size(size) {}
    int getSize() const { return size; }
private:
    int size;  // Size of the packet
};

// FrequencyChannel class represents a frequency channel for communication
class FrequencyChannel {
public:
    FrequencyChannel(double bandwidth = 20.0) : bandwidth(bandwidth) {}
    double getBandwidth() const { return bandwidth; }
private:
    double bandwidth;
};

// Helper function to simulate backoff time


#endif
