#include "laneOne.h"
#include <iostream>

LaneOne::LaneOne()
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
        signal.changeSignalGreen();
        setCounter();
        std::this_thread::sleep_for(10s);
        signal.changeSignalRed();
        setCounter();
        std::cout << "Lane 1 is red" << std::endl;
        sem_post(&laneOneToLaneTwo);
        std::this_thread::sleep_for(30s);
    }
}