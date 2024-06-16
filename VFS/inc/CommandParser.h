#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "ICommandParser.h"
#include <iostream>
#include "CommandController.h"

class CommandParser : public ICommandParser
{
    std::string request;
    ICommandController *controller;

public:
    CommandParser(ICommandController *);
    std::vector<std::string> parseRequest(const std::string &) override;
    bool validateCommand(std::vector<std::string>) override;
    std::string getResponse() override;
};

#endif