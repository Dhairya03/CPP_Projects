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
    int counter = 0;

public:
    int getCounter()
    {
        return counter;
    }

    void switchLight()
    {
        while (true)
        {
            laneTwoToLaneThree.acquire();
            counter = 1;
            std::cout << "Lane 3 is green" << std::endl;
            std::this_thread::sleep_for(10s);
            counter = 0;
            std::cout << "Lane 3 is red" << std::endl;
            laneThreeToLaneFour.release();
            std::this_thread::sleep_for(30s);
        }
    }
};
#endif