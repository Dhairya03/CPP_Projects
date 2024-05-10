#ifndef MOCK_ELEVATOR_H
#define MOCK_ELEVATOR_H

#include "IElevator.h"
#include <mutex>
#include <condition_variable>
#include <gmock/gmock.h>

class MockElevator : public IElevator
{
public:
    MOCK_METHOD(bool, startLift, (std::mutex &, std::condition_variable &), (override));
    MOCK_METHOD(ElevatorDirection, getCurrentDirection, (), (override));
    MOCK_METHOD(bool, addStops, (IRequest *, bool), (override));
    MOCK_METHOD(bool, moveUp, (std::mutex &), (override));
    MOCK_METHOD(bool, moveDown, (std::mutex &), (override));
    MOCK_METHOD(bool, processRequest, (std::mutex &, std::condition_variable &), (override));
    MOCK_METHOD(ElevatorDirection, stopLift, (), (override));
    MOCK_METHOD(int, getCurrentFloor, (), (override));
    MOCK_METHOD(void, setDestinationFloor, (), (override));
    MOCK_METHOD(bool, getRunningStatus, (), (override));
    MOCK_METHOD(void, setRunningStatus, (bool), (override));
};

#endif