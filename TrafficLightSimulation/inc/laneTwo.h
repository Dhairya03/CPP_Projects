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
            laneOneToLaneTwo.acquire();
            counter = 1;
            std::cout << "Lane 2 is green" << std::endl;
            std::this_thread::sleep_for(10s);
            counter = 0;
            std::cout << "Lane 2 is red" << std::endl;
            laneTwoToLaneThree.release();
            std::this_thread::sleep_for(30s);
        }
    }
};
#endif