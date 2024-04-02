#include "laneOne.h"
// #include "semaphores.h"
#include <iostream>

LaneOne::LaneOne()
{
    counterOne = new int;
}
LaneOne::~LaneOne()
{
    delete counterOne;
}
int LaneOne::getCounter()
{
    return *counterOne;
}

void LaneOne::setCounter(int val)
{
    *counterOne = val;
}

void LaneOne::switchLight()
{
    while (start)
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