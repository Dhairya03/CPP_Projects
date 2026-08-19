#ifndef I_COMMAND_CONTROLLER_H
#define I_COMMAND_CONTROLLER_H

#include <iostream>

class ICommandController
{
public:
    virtual bool isValidCommand(const std::string &) = 0;
    virtual bool isValidArgument(const std::string &, const std::string &) = 0;
    virtual void executeCommand() = 0;
    virtual void setResponse(std::string) = 0;
    virtual std::string getResponse() = 0;
};

#endif