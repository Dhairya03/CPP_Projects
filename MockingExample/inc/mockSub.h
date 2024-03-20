#ifndef MOCK_SUB_H
#define MOCK_SUB_H

#include <gmock/gmock.h>
#include "ISub.h"
class MockSub : public ISub
{
public:
    MOCK_METHOD(int, sub, (int, int));
};

#endif