#include "laneTwo.h"
#include <iostream>

LaneTwo::LaneTwo(ITrafficSignal *trafficSignal) : signal(trafficSignal)
{
    counter = new int;
    isLoopStart = new bool;
}
LaneTwo::~LaneTwo()
{
    delete counter;
    delete isLoopStart;
}

void LaneTwo::switchLight()
{
    while (getLoopStart())
    {
        sem_wait(&laneOneToLaneTwo);
        signal->setSignal(Green);
        setCounter(signal);
        std::cout << "lane 2 is green" << std::endl;
        std::this_thread::sleep_for(10s);
        signal->setSignal(Red);
        setCounter(signal);
        std::cout << "lane 2 is red" << std::endl;
        sem_post(&laneTwoToLaneThree);
        std::this_thread::sleep_for(30s);
    }
}