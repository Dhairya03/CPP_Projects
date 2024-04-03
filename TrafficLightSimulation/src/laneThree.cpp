#include "laneThree.h"

#include <iostream>

LaneThree::LaneThree(ITrafficSignal *trafficSignal) : signal(trafficSignal)
{
    counter = new int;
    isLoopStart = new bool;
}

LaneThree::~LaneThree()
{
    delete counter;
    delete isLoopStart;
}

void LaneThree::switchLight()
{
    while (getLoopStart())
    {
        sem_wait(&laneTwoToLaneThree);
        signal->setSignal(Green);
        setCounter(signal);
        std::cout << "lane 3 is green" << std::endl;
        std::this_thread::sleep_for(10s);
        signal->setSignal(Red);
        setCounter(signal);
        std::cout << "lane 3 is red" << std::endl;
        sem_post(&laneThreeToLaneFour);
        std::this_thread::sleep_for(30s);
    }
}