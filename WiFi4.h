#ifndef WIFI4_H
#define WIFI4_H

#include "Commons.h"

class WiFi4 : public Communication {
public:
    void simulate(int numUsers, int numAPs) override;

private:
    int getBackoffTime(int numUsers) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, MAX_BACKOFF_TIME * numUsers);
    return dis(gen);
}

};

#endif
