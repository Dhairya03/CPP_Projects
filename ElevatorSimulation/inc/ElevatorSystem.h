#ifndef ELEVATOR_SYSTEM_H
#define ELEVATOR_SYSTEM_H

#include "IElevator.h"

class ElevatorSystem 
{
    IElevator *elevator1;
    IElevator *elevator2;
    int minFloor, maxFloor;
    Request request;

public:
    ElevatorSystem();
    ElevatorSystem(IElevator *, IElevator *);
    void startElevator();
    int findNearestElevator(Request &);
    bool addRequest(Request &,bool type);
    void move();
};

#endif