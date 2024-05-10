#include "Request.h"
#include "constants.h"
#include <iostream>
#include <random>

Request::Request()
{
    direction = new bool;
    floor = new int;
}

int Request::generateRandomFloor(int lower_bound, int upper_bound)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(lower_bound, upper_bound);
    int random_number = distrib(gen);
    return random_number;
}

void Request::setDirection(bool requestDirection)
{
    *direction = requestDirection;
}

void Request::setFloor()
{
    *floor = generateRandomFloor(-2, 7);
}

int Request::getFloor() const
{
    return *floor;
}

bool Request::getDirection() const
{
    return *direction;
}