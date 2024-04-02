#include "laneTwo.h"
#include <iostream>
#include "semaphores.cpp"


LaneTwo::LaneTwo()
{
    counterTwo = new int;
}
LaneTwo::~LaneTwo()
{
    delete counterTwo;
}
int LaneTwo::getCounter()
{
    return *counterTwo;
}
void LaneTwo::setCounter(int val)
{
    *counterTwo = val;
}

void LaneTwo::switchLight()
{
    while (start)
    {
        laneOneToLaneTwo.acquire();
        setCounter(1);
        std::cout << "Lane 2 is green" << std::endl;
        std::this_thread::sleep_for(10s);
        setCounter(0);
        std::cout << "Lane 2 is red" << std::endl;
        laneTwoToLaneThree.release();
        std::this_thread::sleep_for(30s);
    }
}