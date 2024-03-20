#ifndef MOCK_ADD_H
#define MOCK_ADD_H

#include <gmock/gmock.h>
#include <iostream>
#include "IAdd.h"
class MockAdd : public IAdd
{
public:
    MOCK_METHOD(int, add, (int, int),(override));
};

#endif