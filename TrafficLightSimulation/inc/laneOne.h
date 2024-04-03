#ifndef LANE_ONE_H
#define LANE_ONE_H
#include "lane.h"
#include <thread>
#include <chrono>
#include <semaphore>
#include <mutex>
#include "trafficSignal.h"

#include "constants.h"

using namespace std::chrono;

class LaneOne : public Lane
{
    int laneNumber = 1;
    // int *counterOne = 0;
    // TrafficSignal signal;
    // bool start = false;

public:
    LaneOne();

    ~LaneOne();

    // int getLoopStart();

    // void setLoopStart(int);

    // int getCounter();

    // void setCounter();

    void switchLight();
};
#endif