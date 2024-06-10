#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <ICommandParser.h>
#include <iostream>
#include <CommandController.h>

class CommandParser : public ICommandParser
{
    std::string request;
    CommandController *controller;
    FileSystem *fs;

public:
    CommandParser(FileSystem *);
    bool parseRequest(std::string) override;
    bool validateCommand(std::string) override;
};

#endif