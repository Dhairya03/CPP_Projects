#include "ElevatorSystem.h"
#include <iostream>

// ElevatorSystem::ElevatorSystem()
// {
// }

ElevatorSystem::ElevatorSystem(IElevator *lift1, IElevator *lift2) : elevator1(lift1), elevator2(lift2)
{
}

void ElevatorSystem::startElevator()
{
    std::cout << "Elevator system has started" << std::endl;
}

int ElevatorSystem::findNearestElevator(Request &currentRequest)
{
    int assignedLift;
    int distanceToElevator1 = abs(currentRequest.getFloor() - elevator1->getCurrentFloor());
    int distanceToElevator2 = abs(currentRequest.getFloor() - elevator2->getCurrentFloor());

    if (elevator1->getCurrentDirection() == Idle && elevator1->getRunningStatus() == false && elevator2->getCurrentDirection() == Idle && elevator2->getRunningStatus() == false)
    {
        assignedLift = (distanceToElevator1 <= distanceToElevator2) ? 1 : 2;
    }

    else if (elevator1->getCurrentDirection() == Idle && elevator1->getRunningStatus() == false && elevator2->getCurrentDirection() != Idle)
    {
        if (distanceToElevator1 <= distanceToElevator2)
            assignedLift = 1;
        else if (currentRequest.getDirection() == elevator2->getCurrentDirection())
            assignedLift = 2;
        else
            assignedLift = 1;
    }

    else if (elevator1->getCurrentDirection() != Idle && elevator2->getCurrentDirection() == Idle)
    {
        if (distanceToElevator1 <= distanceToElevator2)
            assignedLift = 2;
        else if (currentRequest.getDirection() == elevator2->getCurrentDirection())
            assignedLift = 1;
        else
            assignedLift = 2;
    }
    else
    {
        if (elevator1->getCurrentDirection() == currentRequest.getDirection() && elevator2->getCurrentDirection() == currentRequest.getDirection())
        {
            assignedLift = (distanceToElevator1 <= distanceToElevator2) ? 1 : 2;
        }

        if (elevator1->getCurrentDirection() == currentRequest.getDirection())
            assignedLift = 1;

        if (elevator2->getCurrentDirection() == currentRequest.getDirection())
            assignedLift = 2;

        assignedLift = (distanceToElevator1 <= distanceToElevator2) ? 1 : 2;
    }
    std::cout << "Assigned Lift" << assignedLift << std::endl;
    return assignedLift;
}

bool ElevatorSystem::addRequest(Request &currentRequest, bool type)
{
    // std::cout << "Request recieved is" << currentRequest.getDirection() << "," << currentRequest.getFloor() << std::endl;
    // request = currentRequest;
    // std::cout << "Request recieved is" << request.getDirection() << "," << request.getFloor() << std::endl;

    // find the nearestElevator
    int lift = findNearestElevator(currentRequest);

    if (lift == 1)
        elevator1->addStops(currentRequest, type);
    else if (lift == 2)
        elevator2->addStops(currentRequest, type);
    else
        std::cout << "Invalid request" << std::endl;
    // assign lift
}

void ElevatorSystem::move()
{
    // moveElevator
}