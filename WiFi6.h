#ifndef WIFI6_H
#define WIFI6_H

#include "Commons.h"

class WiFi6 : public Communication {
public:
    void simulate(int numUsers, int numAPs) override;
};

#endif
