#include "laneThree.h"
#include "semaphores.cpp"

#include <iostream>

LaneThree::LaneThree()
{
    counterThree = new int;
}
LaneThree::~LaneThree()
{
    delete counterThree;
}
int LaneThree:: getCounter()
{
    return *counterThree;
}

void LaneThree::setCounter(int val)
{
    *counterThree = val;
}

void LaneThree::switchLight()
{
    while (start)
    {
        laneTwoToLaneThree.acquire();
        setCounter(1);
        std::cout << "Lane 3 is green" << std::endl;
        std::this_thread::sleep_for(10s);
        setCounter(0);
        std::cout << "Lane 3 is red" << std::endl;
        laneThreeToLaneFour.release();
        std::this_thread::sleep_for(30s);
    }
}