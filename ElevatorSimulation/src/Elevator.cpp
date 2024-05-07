#include "Elevator.h"
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono;

Elevator::Elevator(ElevatorDirection direction, int currentFloor) : direction(direction), currentFloor(currentFloor)
{
    running = new bool;
}

bool Elevator::startLift()
{
    std::cout << "Lift started" << std::endl;
    while (*running)
    {
        std::cout << std::this_thread::get_id() << "Upstops Size " << upStops.size() << "Downstops size" << downStops.size() << std::endl;

        if (upStops.size() != 0 || downStops.size() != 0)
        {
            processRequest();
        }
        else
        {
            std::cout << std::this_thread::get_id() << "Waiting for the requests" << std::endl;
            std::this_thread::sleep_for(1s);
        }
    }
}

ElevatorDirection Elevator::getCurrentDirection()
{
    return this->direction;
}

bool Elevator::addStops(Request &request, bool type)
{
    bool isAdded = false;
    if (request.getDirection() == Up)
    {
        upStops.push_back(std::make_pair(request.getFloor(), type));
        sort(upStops.begin(), upStops.end());
        isAdded = true;
    }
    else if (request.getDirection() == Down)
    {
        downStops.push_back(std::make_pair(request.getFloor(), type));
        sort(downStops.begin(), downStops.end());
        isAdded = true;
    }
    else
    {
        std::cout << "Invalid request" << std::endl;
    }
    return isAdded;
}

bool Elevator::moveUp()
{
    if (currentFloor < 7)
    {
        std::cout << "Lift " << std::this_thread::get_id() << "is moving from" << currentFloor << "to" << currentFloor + 1 << std::endl;
        currentFloor++;
        std::this_thread::sleep_for(1s);
    }
}

bool Elevator::moveDown()
{
    if (currentFloor > -2)
    {
        std::cout << "Lift " << std::this_thread::get_id() << "is moving from" << currentFloor << "to" << currentFloor - 1 << std::endl;
        currentFloor--;
        std::this_thread::sleep_for(1s);
    }
}

bool Elevator::processRequest()
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
        std::cout << "direction of lift " << std::this_thread::get_id() << "is Up" << std::endl;
        std::this_thread::sleep_for(1s);
    }
    else if (direction == LiftDown)
    {
        requestFloor = downStops[0].first;
        requestType = downStops[0].second;
        isRequestBeingProcessed = true;
        downStops.erase(downStops.begin());
        std::cout << "direction of lift" << std::this_thread::get_id() << " is down" << std::endl;
        std::this_thread::sleep_for(1s);
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
                moveUp();
            }
            else
            {
                moveDown();
            }
        }

        if (requestFloor == currentFloor)
        {
            stopLift();
            std::cout << "Lift is stopped at floor" << currentFloor << std::endl;
        }

        if (requestType == 0)
        {
            std::cout << "Enter destination floor" << std::endl;
            std::cin >> destinationFloor;
            std::cout << "DestinationFloor: " << destinationFloor << std::endl;
            // where to add destination floor ???? in upStops or downStops or current working queue
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
}

bool Elevator::stopLift()
{
    direction = Idle;
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