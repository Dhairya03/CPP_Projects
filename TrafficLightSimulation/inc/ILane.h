#ifndef I_LANE_H
#define I_LANE_H
class ILane
{
public:
    virtual int getCounter() = 0;
    virtual void setCounter() = 0;
    virtual void switchLight() = 0;
};

#endif