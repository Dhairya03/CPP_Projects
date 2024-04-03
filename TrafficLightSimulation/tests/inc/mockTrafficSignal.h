#ifndef MOCK_TRAFFIC_SIGNAL_H
#define MOCK_TRAFFIC_SIGNAL_H

#include "ITrafficSignal.h"
#include <gmock/gmock.h>

class MockTrafficSignal : public ITrafficSignal
{
public:
    MOCK_METHOD(int, getSignal, (), (override));
    MOCK_METHOD(void, setSignal, (int), (override));
};

#endif