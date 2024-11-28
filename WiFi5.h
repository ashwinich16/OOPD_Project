#ifndef WIFI5_H
#define WIFI5_H

#include "Commons.h"

// WiFi 5 - MU-MIMO Simulation
class WiFi5 : public Communication {
public:
    void simulate(int numUsers, int numAPs) override;
};

#endif
