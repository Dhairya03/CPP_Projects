#ifndef MOCK_COMMAND_CONTROLLER_H
#define MOCK_COMMAND_CONTROLLER_H

#include <gmock/gmock.h>
#include "ICommandController.h"

class MockCommandController : public ICommandController
{
public:
    MOCK_METHOD(bool, isValidCommand, (const std::string &), (override));
    MOCK_METHOD(bool, isValidArgument, (const std::string &, const std::string &), (override));
    MOCK_METHOD(void, executeCommand, (), (override));
    MOCK_METHOD(void, setResponse, (std::string), (override));
    MOCK_METHOD(std::string, getResponse, (), (override));
};

#endif