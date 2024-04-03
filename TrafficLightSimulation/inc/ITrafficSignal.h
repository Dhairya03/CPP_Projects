#ifndef I_TRAFFIC_SIGNAL_H
#define I_TRAFFIC_SIGNAL_H

class ITrafficSignal
{
public:
    virtual int getSignal() = 0;
    virtual void setSignal(int) = 0;
};

#endif