#ifndef MOCK_COMMAND_CONTROLLER_H
#define MOCK_COMMAND_CONTROLLER_H

#include <gmock/gmock.h>
#include <ICommandController.h>

class MockCommandController : public ICommandController
{
public:
    MOCK_METHOD(bool, isValidCommand, (), (override));
    MOCK_METHOD(bool, isValidArgument, (), (override));
    MOCK_METHOD(void, executeCommand, (), (override));
    MOCK_METHOD(void, setResponse, (std::string), (override));
};

#endif