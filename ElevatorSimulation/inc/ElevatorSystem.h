#ifndef ELEVATOR_SYSTEM_H
#define ELEVATOR_SYSTEM_H

#include "IElevator.h"

class ElevatorSystem 
{
    IElevator *elevator1;
    IElevator *elevator2;
    int minFloor, maxFloor;

public:
    ElevatorSystem();
    ElevatorSystem(IElevator *, IElevator *);
    void startElevator();
    int findNearestElevator(IRequest *);
    bool addRequest(IRequest *,bool type);
    void move();
};

#endif