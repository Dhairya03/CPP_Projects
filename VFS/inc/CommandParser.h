#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <ICommandParser.h>
#include <iostream>
#include <CommandController.h>

class CommandParser : public ICommandParser
{
    std::string request;
    CommandController* controller;

public:
    bool parseRequest(std::string);
    bool validateCommand(std::string);
};

#endif