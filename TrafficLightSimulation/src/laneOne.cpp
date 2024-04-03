#include "laneOne.h"
#include <iostream>

LaneOne::LaneOne(ITrafficSignal *trafficSignal) : signal(trafficSignal)
{
    counter = new int;
    isLoopStart = new bool;
}

LaneOne::~LaneOne()
{
    delete counter;
    delete isLoopStart;
}

void LaneOne::switchLight()
{
    while (getLoopStart())
    {
        sem_wait(&laneFourToLaneOne);
        signal->setSignal(Green);
        setCounter(signal);
        std::cout << "Lane 1 is green" << std::endl;
        std::this_thread::sleep_for(10s);
        signal->setSignal(Red);
        setCounter(signal);
        std::cout << "Lane 1 is red" << std::endl;
        sem_post(&laneOneToLaneTwo);
        std::this_thread::sleep_for(30s);
    }
}