#ifndef LANE_ONE_H
#define LANE_ONE_H
#include "lane.h"
#include <thread>
#include <chrono>
#include <semaphore>
#include "constants.h"

using namespace std::chrono;

class LaneOne : public Lane
{
    int laneNumber = 1;
    int counter = 0;

public:
    int getCounter()
    {
        return counter;
    }

    void setCounter(int val)
    {
        std::cout << "value set to 1" << std::endl;
        counter = val;
    }

    void switchLight()
    {
        while (true)
        {
            setCounter(1);
            std::cout << "Lane 1 is green" << std::endl;
            std::this_thread::sleep_for(10s);
            setCounter(0);
            std::cout << "Lane 1 is red" << std::endl;
            laneOneToLaneTwo.release();
            std::this_thread::sleep_for(30s);
            laneFourToLaneOne.acquire();
        }
    }
};
#endif