#ifndef I_COMMAND_CONTROLLER_H
#define I_COMMAND_CONTROLLER_H

#include <iostream>

class ICommandController
{
public:
    virtual bool isValidCommand() = 0;
    virtual bool isValidArgument() = 0;
    virtual void executeCommand() = 0;
    virtual void setResponse(std::string) = 0;
};

#endif