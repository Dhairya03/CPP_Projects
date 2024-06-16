#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H

#include "ICommandController.h"
#include <iostream>
#include "FileSystem.h"

class CommandController : public ICommandController
{
    std::string command = "";
    std::string argument1 = "";
    std::string argument2 = "";
    std::string response = "";
    IFileSystem *fs = nullptr;

public:
    CommandController(IFileSystem *);
    bool isValidCommand(const std::string &);
    bool isValidArgument(const std::string &, const std::string &);
    void executeCommand();
    void setResponse(std::string);
    std::string getResponse();
};

#endif