#ifndef LANE_THREE_H
#define LANE_THREE_H
#include "lane.h"
#include <thread>
#include <chrono>
#include "constants.h"

using namespace std::chrono;

class LaneThree : public Lane
{
    int laneNumber = 3;
    int *counterThree = 0;

public:
    bool start = false;

    LaneThree();

    ~LaneThree();

    int getCounter();

    void setCounter(int val);

    void switchLight();
};
#endif