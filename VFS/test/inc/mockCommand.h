#ifndef MOCK_COMMAND_H
#define MOCK_COMMAND_H

#include <ICommand.h>
#include <gmock/gmock.h>

class MockCommand : public ICommand
{
public:
    MOCK_METHOD(std::string, execute, (IFileSystem &), (override));
};
#endif