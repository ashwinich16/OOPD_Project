#ifndef WIFI5_H
#define WIFI5_H

#include "Commons.h"

class WiFi5 : public Communication {
public:
    void simulate(int numUsers, int numAPs) override;
};

#endif
