#include "laneThree.h"

#include <iostream>

LaneThree::LaneThree()
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

        signal.changeSignalGreen();
        setCounter();
        std::this_thread::sleep_for(10s);
        signal.changeSignalRed();
        setCounter();
        std::cout << "lane 3 is red" << std::endl;

        sem_post(&laneThreeToLaneFour);
        std::this_thread::sleep_for(30s);
    }
}