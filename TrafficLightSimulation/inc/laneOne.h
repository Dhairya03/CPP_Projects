#ifndef LANE_ONE_H
#define LANE_ONE_H
#include "lane.h"
#include <thread>
#include <chrono>
#include <semaphore>
#include <mutex>
#include "constants.h"

using namespace std::chrono;

class LaneOne : public Lane
{
    int laneNumber = 1;
    int *counterOne = 0;

public:
    bool start=false;

    LaneOne();

    ~LaneOne();

    int getCounter();

    void setCounter(int val);

    void switchLight();    
};
#endif