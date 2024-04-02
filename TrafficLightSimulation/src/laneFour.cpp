#include "laneFour.h"
#include "semaphores.cpp"

#include <iostream>

LaneFour::LaneFour()
{
    counterFour = new int;
}
LaneFour::~LaneFour()
{
    delete counterFour;
}
int LaneFour::getCounter()
{
    return *counterFour;
}

void LaneFour::setCounter(int val)
{
    *counterFour = val;
}

void LaneFour::switchLight()
{
    while (start)
    {
        laneThreeToLaneFour.acquire();
        setCounter(1);
        std::cout << "Lane 4 is green" << std::endl;
        std::this_thread::sleep_for(10s);
        setCounter(0);
        std::cout << "Lane 4 is red" << std::endl;
        laneFourToLaneOne.release();
        std::this_thread::sleep_for(30s);
    }
}