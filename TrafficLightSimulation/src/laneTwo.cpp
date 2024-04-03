#include "laneTwo.h"
#include <iostream>

LaneTwo::LaneTwo()
{
    counter = new int;
    isLoopStart = new bool;
}
LaneTwo::~LaneTwo()
{
    delete counter;
    delete isLoopStart;
}
// int LaneTwo::getCounter()
// {
//     return *counterTwo;
// }
// void LaneTwo::setCounter()
// {
//     *counterTwo = signal.getSignal();
// }

void LaneTwo::switchLight()
{
    while (getLoopStart())
    {
        sem_wait(&laneOneToLaneTwo);
        signal.changeSignalGreen();
        setCounter();
        std::this_thread::sleep_for(10s);
        signal.changeSignalRed();
        setCounter();
        std::cout << "lane 2 is red" << std::endl;
        sem_post(&laneTwoToLaneThree);
        std::this_thread::sleep_for(30s);
    }
}