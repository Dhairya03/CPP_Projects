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
            laneThreeToLaneFour.acquire();
            counter = 1;
            std::cout << "Lane 4 is green" << std::endl;

            std::this_thread::sleep_for(10s);
            counter = 0;
            std::cout << "Lane 4 is red" << std::endl;
            laneFourToLaneOne.release();
            std::this_thread::sleep_for(30s);
        }
    }
};
#endif