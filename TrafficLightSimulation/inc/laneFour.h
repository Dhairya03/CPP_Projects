#ifndef LANE_FOUR_H
#define LANE_FOUR_H
#include "lane.h"
#include <thread>
#include <chrono>
#include "constants.h"
using namespace std::chrono;

class LaneFour : public Lane
{
    int laneNumber = 4;
    int *counterFour = 0;

public:
    bool start = false;

    LaneFour();

    ~LaneFour();

    int getCounter();

    void setCounter(int val);

    void switchLight();
};
#endif