#ifndef LANE_THREE_H
#define LANE_THREE_H
#include "lane.h"
#include <thread>
#include <chrono>
#include "constants.h"
#include "trafficSignal.h"

using namespace std::chrono;

class LaneThree : public Lane
{
    int laneNumber = 3;
    ITrafficSignal *signal;

public:
    LaneThree(ITrafficSignal*);

    ~LaneThree();

    void switchLight();
};
#endif