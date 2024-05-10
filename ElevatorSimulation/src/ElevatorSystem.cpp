#include "ElevatorSystem.h"
#include <iostream>

ElevatorSystem::ElevatorSystem(IElevator *lift1, IElevator *lift2) : elevator1(lift1), elevator2(lift2)
{
}

int ElevatorSystem::findNearestElevator(IRequest *currentRequest)
{
    int assignedLift;
    int distanceToElevator1 = abs(currentRequest->getFloor() - elevator1->getCurrentFloor());
    int distanceToElevator2 = abs(currentRequest->getFloor() - elevator2->getCurrentFloor());

    if (elevator1->getCurrentDirection() == Idle && elevator1->getRunningStatus() == false && elevator2->getCurrentDirection() == Idle && elevator2->getRunningStatus() == false)
    {
        assignedLift = (distanceToElevator1 <= distanceToElevator2) ? 1 : 2;
    }

    else if (elevator1->getCurrentDirection() == Idle && elevator1->getRunningStatus() == false && elevator2->getCurrentDirection() != Idle)
    {
        if (distanceToElevator1 <= distanceToElevator2)
            assignedLift = 1;
        else if ((currentRequest->getDirection() == 0 && ElevatorDirection::LiftUp == elevator2->getCurrentDirection()) || (currentRequest->getDirection() == 1 && ElevatorDirection::LiftDown == elevator2->getCurrentDirection()))
            assignedLift = 2;
        else
            assignedLift = 1;
    }

    else if (elevator1->getCurrentDirection() != Idle && elevator2->getCurrentDirection() == Idle)
    {
        if (distanceToElevator2 <= distanceToElevator1)
            assignedLift = 2;
        else if ((currentRequest->getDirection() == 0 && elevator1->getCurrentDirection() == ElevatorDirection::LiftUp) || (currentRequest->getDirection() == 1 && ElevatorDirection::LiftDown == elevator1->getCurrentDirection()))
            assignedLift = 1;
        else
            assignedLift = 2;
    }
    else
    {
        if (elevator1->getCurrentDirection() == currentRequest->getDirection() && elevator2->getCurrentDirection() == currentRequest->getDirection())
        {
            if (currentRequest->getFloor() < elevator1->getCurrentFloor() && currentRequest->getFloor() < elevator2->getCurrentFloor())
            {
                assignedLift = (elevator1->getCurrentFloor() > elevator2->getCurrentFloor()) ? 1 : 2;
            }
            else if (currentRequest->getFloor() > elevator1->getCurrentFloor() && currentRequest->getFloor() > elevator2->getCurrentFloor())
            {
                assignedLift = (elevator1->getCurrentFloor() > elevator2->getCurrentFloor()) ? 1 : 2;
            }
            else
            {
                if (currentRequest->getDirection() == Up)
                {
                    assignedLift = (elevator1->getCurrentFloor() < elevator2->getCurrentFloor()) ? 1 : 2;
                }
                else if (currentRequest->getDirection() == Down)
                {
                    assignedLift = (elevator1->getCurrentFloor() > elevator2->getCurrentFloor()) ? 1 : 2;
                }
            }
        }

        else if (elevator1->getCurrentDirection() == currentRequest->getDirection())
            assignedLift = 1;

        else if (elevator2->getCurrentDirection() == currentRequest->getDirection())
            assignedLift = 2;

        else
            assignedLift = (distanceToElevator1 <= distanceToElevator2) ? 1 : 2;
    }
    std::cout << "Assigned Lift " << assignedLift << std::endl;
    return assignedLift;
}

bool ElevatorSystem::addRequest(IRequest *currentRequest, bool type)
{
    bool isRequestAdded = false;
    int lift = findNearestElevator(currentRequest);
    if (lift == 1)
    {
        isRequestAdded = true;
        elevator1->addStops(currentRequest, type);
    }
    else if (lift == 2)
    {
        isRequestAdded = true;
        elevator2->addStops(currentRequest, type);
    }
    else
        std::cout << "Invalid request" << std::endl;
    return isRequestAdded;
}
