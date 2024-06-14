#ifndef I_COMMAND_PARSER_H
#define I_COMMAND_PARSER_H

#include <iostream>
#include <vector>

class ICommandParser
{
public:
    virtual std::vector<std::string> parseRequest(const std::string &) = 0;
    virtual bool validateCommand(std::vector<std::string>) = 0;
    virtual std::string getResponse() = 0;
};

#endif