#ifndef I_COMMAND_PARSER_H
#define I_COMMAND_PARSER_H

#include <iostream>

class ICommandParser
{
public:
    virtual bool parseRequest(std::string) = 0;
    virtual bool validateCommand(std::string) = 0;
};

#endif