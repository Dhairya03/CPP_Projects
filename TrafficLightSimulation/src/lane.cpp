#include "lane.h"
#include <iostream>
Lane::Lane()
{
    counter = new int;
    isLoopStart = new bool;
}

Lane::Lane(ITrafficSignal *trafficSignal) : signal(trafficSignal)
{
    counter = new int;
    isLoopStart = new bool;
}

int Lane::getLoopStart()
{
    return *isLoopStart;
}

void Lane::setLoopStart(bool loopChoice)
{
    *isLoopStart = loopChoice;
}

int Lane::getCounter()
{
    return *counter;
}

void Lane::setCounter(ITrafficSignal *signal)
{
    *counter = signal->getSignal();
}

Lane::~Lane()
{
    delete counter;
    delete isLoopStart;
}

void Lane::switchLight(sem_t &wait, sem_t &post, int laneNumber)
{
    while (getLoopStart())
    {
        sem_wait(&wait);
        signal->setSignal(Green);
        setCounter(signal);
        std::cout << "lane " << laneNumber << " is green" << std::endl;
        std::this_thread::sleep_for(10s);
        signal->setSignal(Red);
        setCounter(signal);
        std::cout << "lane " << laneNumber << " is red" << std::endl;
        sem_post(&post);
        std::this_thread::sleep_for(30s);
    }
}