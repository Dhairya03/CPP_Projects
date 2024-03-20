#ifndef MOCK_MULTIPLY_H
#define MOCK_MULTIPLY_H

#include <gmock/gmock.h>
#include "IMultiply.h"
class MockMultiply : public IMultiply
{
public:
    MOCK_METHOD(int, multiply, (int, int));
};

#endif