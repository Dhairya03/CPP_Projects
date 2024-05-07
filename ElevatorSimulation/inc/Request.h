#ifndef REQUEST_H
#define REQUEST_H

#include "constants.h"

class Request
{
    bool *direction = 0;
    int *floor = 0;

public:
    Request();

    Request(const Request& request);

    int generateRandomFloor();

    void setDirection(bool direction);

    void setFloor();

    int getFloor() const;

    bool getDirection() const;
};

#endif