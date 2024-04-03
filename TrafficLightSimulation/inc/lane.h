#ifndef LANE_H
#define LANE_H

#include "ILane.h"
#include "trafficSignal.h"

class Lane : public ILane
{
public:
    int *counter = 0;
    bool *isLoopStart = 0;
    ITrafficSignal *signal;

public:
    Lane();
    Lane(ITrafficSignal *);
    int getLoopStart();
    void setLoopStart(bool);
    int getCounter();
    void setCounter(ITrafficSignal *);
    void switchLight(sem_t &, sem_t &, int);
    ~Lane();
};

#endif