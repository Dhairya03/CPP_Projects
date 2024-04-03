#include "laneFour.h"
#include <iostream>

LaneFour::LaneFour()
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
        signal.changeSignalGreen();
        setCounter();
        std::this_thread::sleep_for(10s);
        signal.changeSignalRed();
        setCounter();
        std::cout << "lane 4 is red" << std::endl;
        sem_post(&laneFourToLaneOne);
        std::this_thread::sleep_for(30s);
    }
}