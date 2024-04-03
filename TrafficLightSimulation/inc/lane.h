#ifndef LANE_H
#define LANE_H

#include "ILane.h"
#include "trafficSignal.h"

class Lane : public ILane
{
protected:
    int *counter = 0;
    bool *isLoopStart = 0;
    TrafficSignal signal;

public:
    Lane();
    int getLoopStart();
    void setLoopStart(bool);
    int getCounter();
    void setCounter();
    ~Lane();
};

#endif