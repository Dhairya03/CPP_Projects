#ifndef LANE_FOUR_H
#define LANE_FOUR_H

#include "lane.h"
#include <thread>
#include <chrono>
#include "trafficSignal.h"
#include "constants.h"

using namespace std::chrono;

class LaneFour : public Lane
{
    int laneNumber = 4;
    ITrafficSignal *signal;

public:
    LaneFour(ITrafficSignal *);

    ~LaneFour();

    void switchLight();
};
#endif