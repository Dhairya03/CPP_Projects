#include "laneFour.h"
#include <iostream>

LaneFour::LaneFour(ITrafficSignal *trafficSignal) : signal(trafficSignal)
{
    counter = new int;
    isLoopStart = new bool;
}

LaneFour::~LaneFour()
{
    delete counter;
    delete isLoopStart;
}

void LaneFour::switchLight()
{
    while (getLoopStart())
    {
        sem_wait(&laneThreeToLaneFour);
        signal->setSignal(Green);
        setCounter(signal);
        std::cout << "lane 4 is green" << std::endl;
        std::this_thread::sleep_for(10s);
        signal->setSignal(Red);
        setCounter(signal);
        std::cout << "lane 4 is red" << std::endl;
        sem_post(&laneFourToLaneOne);
        std::this_thread::sleep_for(30s);
    }
}