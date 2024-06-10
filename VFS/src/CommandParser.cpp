#include <CommandParser.h>
#include <sstream>
#include <vector>
#include <constants.h>

CommandParser::CommandParser(FileSystem *fs) : fs(fs)
{
}

bool CommandParser::parseRequest(std::string request)
{
    std::string command;
    std::string argument1, argument2;

    command = request.substr(0, request.find(" "));
    argument1 = request.substr(request.find(" ") + 1);
    argument2 = argument1.substr(argument1.find(" ") + 1);
    argument1 = argument1.substr(0, argument1.find(" "));

    std::cout << command << std::endl;
    std::cout << argument1 << " " << argument2 << std::endl;

    controller = new CommandController(fs,command, argument1, argument2);
    return true;
}

bool CommandParser::validateCommand(std::string request)
{
    bool isValidCommand = false;
    if (controller->isValidCommand())
    {
        if (controller->isValidArgument())
        {
            isValidCommand = true;
            controller->executeCommand();
        }
        else
        {
            std::cout << "invalid option or argument" << std::endl;
        }
    }
    else
    {
        std::cout << "command not found" << std::endl;
    }
    return isValidCommand;
}