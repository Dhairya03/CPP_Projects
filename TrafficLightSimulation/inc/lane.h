#ifndef LANE_H
#define LANE_H

#include "ILane.h"
#include "trafficSignal.h"

class Lane : public ILane
{
public:
    int *counter = 0;
    bool *isLoopStart = 0;
    ITrafficSignal *iSignal;

public:
    Lane();
    Lane(ITrafficSignal *);
    int getLoopStart();
    void setLoopStart(bool);
    int getCounter();
    void setCounter(ITrafficSignal *);
    ~Lane();
};

#endif