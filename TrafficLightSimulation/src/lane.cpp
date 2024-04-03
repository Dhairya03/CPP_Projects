#include "lane.h"
#include <iostream>
Lane::Lane()
{
}
Lane::Lane(ITrafficSignal *trafficSignal) : iSignal(trafficSignal)
{
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
}