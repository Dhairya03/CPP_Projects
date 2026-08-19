#ifndef IELEVATOR_H
#define IELEVATOR_H

#include "Request.h"
#include <mutex>
#include <condition_variable>

class IElevator
{
public:
    virtual bool startLift(std::mutex &) = 0;
    virtual ElevatorDirection getCurrentDirection() = 0;
    virtual bool addStops(IRequest *, bool) = 0;
    virtual bool moveUp(std::mutex &) = 0;
    virtual bool moveDown(std::mutex &m) = 0;
    virtual bool processRequest(std::mutex &) = 0;
    virtual ElevatorDirection stopLift() = 0;
    virtual int getCurrentFloor() = 0;
    virtual bool getRunningStatus() = 0;
    virtual void setRunningStatus(bool) = 0;
    virtual bool isValidDestinationFloor(int) = 0;
};

#endif