#ifndef LANE_TWO_H
#define LANE_TWO_H
#include "lane.h"
#include <thread>
#include <chrono>
#include "constants.h"

using namespace std::chrono;

class LaneTwo : public Lane
{
    int laneNumber = 2;
    int *counterTwo = 0;

public:
    bool start = false;
    LaneTwo();

    ~LaneTwo();

    int getCounter();

    void setCounter(int val);

    void switchLight();
};
#endif