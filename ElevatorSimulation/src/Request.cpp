#include "Request.h"
#include "constants.h"
#include <iostream>
#include <random>

Request::Request()
{
    direction = new bool;
    floor = new int;
}

Request::Request(const Request &request)
{
    direction = new bool;
    floor = new int;
    *direction = *request.direction;
    *floor = *request.floor;
}

int Request::generateRandomFloor()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int lower_bound = -2;
    int upper_bound = 7;
    std::uniform_int_distribution<> distrib(lower_bound, upper_bound);
    int random_number = distrib(gen);
    return random_number;
}

void Request::setDirection(bool requestDirection)
{
    *direction = requestDirection;
    // std::cout << "void wala function : " << &direction << std::endl;
    // std::cout << "Request Direction : " << &requestDirection << std::endl;
}

void Request::setFloor()
{
    *floor = generateRandomFloor();
}

int Request::getFloor() const
{
    return *floor;
}

bool Request::getDirection() const
{
    return *direction;
}