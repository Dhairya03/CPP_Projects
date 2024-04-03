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
    // int *counterFour = 0;
    // TrafficSignal signal;
    // bool isLoopStart = false;

public:
    LaneFour();

    ~LaneFour();

    // int getLoopStart();

    // void setLoopStart(int);

    // int getCounter();

    // void setCounter();

    void switchLight();
};
#endif