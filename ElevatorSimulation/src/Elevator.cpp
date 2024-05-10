#include "Elevator.h"
#include "InputValidator.h"
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::chrono;

Elevator::Elevator(int id, ElevatorDirection direction, int currentFloor) : liftId(id), direction(direction), currentFloor(currentFloor)
{
    running = new bool;
}

bool Elevator::startLift(std::mutex &mutex)
{
    bool isLiftStarted = false;
    mutex.lock();
    std::cout << "Lift " << liftId << " is at " << currentFloor << " floor" << std::endl;
    mutex.unlock();
    mutex.lock();
    std::cout << "Lift " << liftId << " is waiting for the requests" << std::endl;
    mutex.unlock();
    while (true)
    {
        if (upStops.size() != 0 || downStops.size() != 0)
        {
            setRunningStatus(true);
            break;
        }
    }
    while (*running)
    {
        isLiftStarted = true;
        if (upStops.size() != 0 || downStops.size() != 0)
        {
            processRequest(mutex);
        }
        else
        {
            mutex.lock();
            std::cout << "Lift " << liftId << " is waiting for the requests" << std::endl;
            mutex.unlock();
            std::this_thread::sleep_for(1s);
        }
    }
    return isLiftStarted;
}

ElevatorDirection Elevator::getCurrentDirection()
{
    return this->direction;
}

bool Elevator::addStops(IRequest *request, bool type)
{
    bool isAdded = false;
    if (request->getDirection() == Up)
    {
        upStops.push_back(std::make_pair(request->getFloor(), type));
        sort(upStops.begin(), upStops.end());
        isAdded = true;
    }
    else if (request->getDirection() == Down)
    {
        downStops.push_back(std::make_pair(request->getFloor(), type));
        sort(downStops.begin(), downStops.end());
        isAdded = true;
    }
    else
    {
        std::cout << "Invalid request" << std::endl;
    }
    return isAdded;
}

bool Elevator::moveUp(std::mutex &mutex)
{
    bool isMovedUp = false;
    if (currentFloor < 7)
    {
        mutex.lock();
        std::cout << "Lift " << liftId << " is moving from " << currentFloor << " to " << currentFloor + 1 << std::endl;
        mutex.unlock();
        currentFloor++;
        isMovedUp = true;
        std::this_thread::sleep_for(10s);
    }
    return isMovedUp;
}

bool Elevator::moveDown(std::mutex &mutex)
{
    bool isMovedDown = false;
    if (currentFloor > -2)
    {
        mutex.lock();
        std::cout << "Lift " << liftId << " is moving from " << currentFloor << " to " << currentFloor - 1 << std::endl;
        mutex.unlock();
        currentFloor--;
        isMovedDown = true;
        std::this_thread::sleep_for(10s);
    }
    return isMovedDown;
}

bool Elevator::processRequest(std::mutex &mutex)
{
    int requestFloor;
    bool requestType;
    bool isRequestBeingProcessed = false;
    if (direction == LiftUp)
    {
        requestFloor = upStops[0].first;
        requestType = upStops[0].second;
        isRequestBeingProcessed = true;
        upStops.erase(upStops.begin());
    }
    else if (direction == LiftDown)
    {
        requestFloor = downStops[0].first;
        requestType = downStops[0].second;
        isRequestBeingProcessed = true;
        downStops.erase(downStops.begin());
    }
    else
    {
        if (upStops.size() != 0)
        {
            direction = LiftUp;
        }
        else if (downStops.size() != 0)
        {
            direction = LiftDown;
        }
        else
        {
            std::cout << "No request for now" << std::endl;
        }
    }
    if (isRequestBeingProcessed)
    {
        while (currentFloor != requestFloor)
        {
            if (requestFloor > currentFloor)
            {
                moveUp(mutex);
            }
            else
            {
                moveDown(mutex);
            }
        }

        if (requestFloor == currentFloor)
        {
            stopLift();
            mutex.lock();
            std::cout << "Lift " << liftId << " arrived at floor " << currentFloor << std::endl;
            mutex.unlock();
        }

        if (requestType == 0)
        {
            mutex.lock();
            while (true)
            {
                std::cout << "Press destination floor for lift " << liftId << std::endl;
                std::cin >> destinationFloor;
                if (InputValidator::isValidInput() && isValidDestinationFloor(destinationFloor))
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid Destination Floor" << std::endl;
                }
            }
            std::cout << "Lift " << liftId << " DestinationFloor: " << destinationFloor << std::endl;
            mutex.unlock();

            if (destinationFloor > currentFloor)
            {
                upStops.push_back(std::make_pair(destinationFloor, 1));
            }
            else
            {
                downStops.push_back(std::make_pair(destinationFloor, 1));
            }
        }
    }
    return isRequestBeingProcessed;
}

ElevatorDirection Elevator::stopLift()
{
    direction = Idle;
    return direction;
}

int Elevator::getCurrentFloor()
{
    return currentFloor;
}

bool Elevator::getRunningStatus()
{
    return *running;
}

void Elevator::setRunningStatus(bool status)
{
    *running = status;
}

bool Elevator::isValidDestinationFloor(int destinationFloor)
{
    return (destinationFloor <= 7 && destinationFloor >= -2) ? true : false;
}
