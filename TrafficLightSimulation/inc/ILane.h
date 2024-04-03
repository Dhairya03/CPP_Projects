#ifndef I_LANE_H
#define I_LANE_H

#include "ITrafficSignal.h"
#include <semaphore.h>

class ILane
{
public:
    virtual int getCounter() = 0;
    virtual void setCounter(ITrafficSignal *) = 0;
    virtual int getLoopStart() = 0;
    virtual void setLoopStart(bool) = 0;
    virtual void switchLight(sem_t&, sem_t&, int) = 0;
};

#endif