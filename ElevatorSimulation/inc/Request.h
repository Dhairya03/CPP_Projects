#ifndef REQUEST_H
#define REQUEST_H

#include "constants.h"
#include "IRequest.h"

class Request : public IRequest
{
    bool *direction = 0;
    int *floor = 0;

public:
    Request();

    int generateRandomFloor(int ,int);

    void setDirection(bool direction);

    void setFloor();

    int getFloor() const;

    bool getDirection() const;
};

#endif