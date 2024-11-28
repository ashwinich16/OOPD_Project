#ifndef WIFI4_H
#define WIFI4_H

#include "Commons.h"

class WiFi4 : public Communication {
public:
    void simulate(int numUsers, int numAPs) override;

private:
    int getBackoffTime(int numUsers) const;
};

#endif
