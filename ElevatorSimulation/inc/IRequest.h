#ifndef IREQUEST_H
#define IREQUEST_H

class IRequest
{
public:
    virtual int generateRandomFloor(int ,int) = 0;

    virtual void setDirection(bool direction) = 0;

    virtual void setFloor() = 0;

    virtual int getFloor() const = 0;

    virtual bool getDirection() const = 0;
};

#endif