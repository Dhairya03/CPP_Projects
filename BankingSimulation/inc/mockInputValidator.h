#ifndef MOCK_INPUT_VALIDATOR_H
#define MOCK_INPUT_VALIDATOR_H

#include <gmock/gmock.h>
#include "IInputValidator.h"

class MockInputValidator
{
public:
    MOCK_METHOD(bool, isValidInput, (int), ());
};

#endif