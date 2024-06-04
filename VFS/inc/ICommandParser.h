#ifndef I_COMMAND_PARSER_H
#define I_COMMAND_PARSER_H

class ICommandParser
{
public:
    bool parseRequest(std::string);
    bool validateCommand(std::string);
};

#endif