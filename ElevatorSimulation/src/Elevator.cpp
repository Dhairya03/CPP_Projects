#include "Elevator.h"
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

bool Elevator::startLift(std::mutex &mtx, std::condition_variable &cv)
{
    bool isLiftStarted = false;
    mtx.lock();
    std::cout << "Lift " << liftId << " is at " << currentFloor << " floor" << std::endl;
    mtx.unlock();
    while (*running)
    {
        isLiftStarted = true;
        if (upStops.size() != 0 || downStops.size() != 0)
        {
            processRequest(mtx, cv);
        }
        else
        {
            mtx.lock();
            std::cout << "Lift " << liftId << " is waiting for the requests" << std::endl;
            mtx.unlock();
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

bool Elevator::moveUp(std::mutex &mtx)
{
    bool isMovedUp = false;
    if (currentFloor < 7)
    {
        mtx.lock();
        std::cout << "Lift " << liftId << " is moving from " << currentFloor << " to " << currentFloor + 1 << std::endl;
        mtx.unlock();
        currentFloor++;
        isMovedUp = true;
        std::this_thread::sleep_for(10s);
    }
    return isMovedUp;
}

bool Elevator::moveDown(std::mutex &mtx)
{
    bool isMovedDown = false;
    if (currentFloor > -2)
    {
        mtx.lock();
        std::cout << "Lift " << liftId << " is moving from " << currentFloor << " to " << currentFloor - 1 << std::endl;
        mtx.unlock();
        currentFloor--;
        isMovedDown = true;
        std::this_thread::sleep_for(10s);
    }
    return isMovedDown;
}

bool Elevator::processRequest(std::mutex &mtx, std::condition_variable &cv)
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
                moveUp(mtx);
            }
            else
            {
                moveDown(mtx);
            }
        }

        if (requestFloor == currentFloor)
        {
            stopLift();
            mtx.lock();
            std::cout << "Lift " << liftId << " arrived at floor " << currentFloor << std::endl;
            mtx.unlock();
        }

        if (requestType == 0)
        {
            mtx.lock();
            std::cout << "Press destination floor for lift " << liftId << std::endl;
            std::cin >> destinationFloor;
            std::cout << "Lift " << liftId << " DestinationFloor: " << destinationFloor << std::endl;
            mtx.unlock();
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

void Elevator::setDestinationFloor() {}

bool Elevator::getRunningStatus()
{
    return *running;
}

void Elevator::setRunningStatus(bool status)
{
    *running = status;
}