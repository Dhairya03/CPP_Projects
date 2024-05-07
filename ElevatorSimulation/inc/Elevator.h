#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
#include <vector>
#include "constants.h"
#include "IElevator.h"
#include "Request.h"

class Elevator : public IElevator
{
    ElevatorDirection direction;
    int currentFloor;
    int destinationFloor;
    bool *running;
    std::vector<std::pair<int, bool>> upStops;
    std::vector<std::pair<int, bool>> downStops;

public:
    Elevator(ElevatorDirection , int);
    ElevatorDirection getCurrentDirection();
    bool startLift();
    bool addStops(Request &,bool);
    bool moveUp();
    bool moveDown();
    bool processRequest();
    bool stopLift();
    int getCurrentFloor();
    void setDestinationFloor();
    bool getRunningStatus();
    void setRunningStatus(bool);
};

#endif