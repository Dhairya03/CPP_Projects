#ifndef MOCK_REQUEST_H
#define MOCK_REQUEST_H

#include "IRequest.h"
#include <gmock/gmock.h>

class MockRequest : public IRequest
{
public:
    MOCK_METHOD(int, generateRandomFloor, (int, int), (override));
    MOCK_METHOD(void, setDirection, (bool), (override));
    MOCK_METHOD(void, setFloor, (), (override));
    MOCK_METHOD(int, getFloor, (), (const));
    MOCK_METHOD(bool, getDirection, (), (const));
};

#endif