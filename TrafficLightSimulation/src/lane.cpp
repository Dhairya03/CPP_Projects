#include "lane.h"
#include <iostream>

Lane::Lane()
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

void Lane::setCounter()
{
    *counter = signal.getSignal();
}

Lane::~Lane()
{
}