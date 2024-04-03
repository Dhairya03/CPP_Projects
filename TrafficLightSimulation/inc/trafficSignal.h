#ifndef TRAFFIC_SIGNAL_H
#define TRAFFIC_SIGNAL_H

#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>
#include "ITrafficSignal.h"
#include "constants.h"

using namespace std::chrono;

class TrafficSignal : public ITrafficSignal
{
    int *signal = 0;

public:
    TrafficSignal();

    ~TrafficSignal();

    int getSignal();

    void setSignal(int sign);
};

#endif