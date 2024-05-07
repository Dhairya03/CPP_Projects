#ifndef IELEVATOR_H
#define IELEVATOR_H

#include "Request.h"

class IElevator
{
public:
    virtual bool startLift() = 0;
    virtual ElevatorDirection getCurrentDirection() = 0;
    virtual bool addStops(Request &,bool) = 0;
    virtual bool moveUp() = 0;
    virtual bool moveDown() = 0;
    virtual bool processRequest() = 0;
    virtual bool stopLift() = 0;
    virtual int getCurrentFloor() = 0;
    virtual void setDestinationFloor() = 0;
    virtual bool getRunningStatus() = 0;
    virtual void setRunningStatus(bool) = 0;
};

#endif