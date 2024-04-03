#include "trafficSignal.h"

TrafficSignal::TrafficSignal()
{
    signal = new int;
}

TrafficSignal::~TrafficSignal()
{
    delete signal;
}

int TrafficSignal::getSignal()
{
    return *signal;
}

void TrafficSignal::setSignal(int sign)
{
    *signal = sign;
}

void TrafficSignal::changeSignalGreen()
{
    setSignal(1);
}

void TrafficSignal::changeSignalRed()
{
    setSignal(0);
}