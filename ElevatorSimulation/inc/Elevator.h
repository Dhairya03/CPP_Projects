#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
#include <vector>
#include <mutex>
#include "constants.h"
#include "IElevator.h"
#include "Request.h"

class Elevator : public IElevator
{
    ElevatorDirection direction;
    int liftId;
    int currentFloor;
    int destinationFloor;
    bool *running;
    std::vector<std::pair<int, bool>> upStops;
    std::vector<std::pair<int, bool>> downStops;

public:
    Elevator(int, ElevatorDirection, int);
    ElevatorDirection getCurrentDirection();
    bool startLift(std::mutex &);
    bool addStops(IRequest *, bool);
    bool moveUp(std::mutex &);
    bool moveDown(std::mutex &);
    bool processRequest(std::mutex &);
    ElevatorDirection stopLift();
    int getCurrentFloor();
    bool getRunningStatus();
    void setRunningStatus(bool);
    bool isValidDestinationFloor(int);
};

#endif