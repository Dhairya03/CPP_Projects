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
    // int *counterThree = 0;
    // TrafficSignal signal;
    // bool start = false;

public:
    bool start = false;

    LaneThree();

    ~LaneThree();

    // int getLoopStart();

    // void setLoopStart(int);

    // int getCounter();

    // void setCounter();

    void switchLight();
};
#endif