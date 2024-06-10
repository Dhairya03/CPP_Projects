#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H

#include <ICommandController.h>
#include <iostream>
#include <FileSystem.h>

class CommandController : public ICommandController
{
    std::string command;
    std::string argument1;
    std::string argument2;
    std::string response;
    FileSystem *fs;

public:
    CommandController(FileSystem*,std::string, std::string, std::string);
    bool isValidCommand();
    bool isValidArgument();
    void executeCommand();
    void setResponse(std::string);
};

#endif