#include "CommandParser.h"
#include <sstream>
#include <vector>
#include "constants.h"

CommandParser::CommandParser(ICommandController *controller) : controller(controller)
{
}

std::vector<std::string> splitString(const std::string &input, char delimiter = ' ')
{
    std::vector<std::string> parts;
    std::stringstream ss(input);
    std::string part;
    while (std::getline(ss, part, delimiter))
    {
        if (!part.empty())
        {
            parts.push_back(part);
        }
    }
    return parts;
}

std::vector<std::string> CommandParser::parseRequest(const std::string &request)
{
    auto requestTokens = splitString(request);
    return requestTokens;
}

bool CommandParser::validateCommand(std::vector<std::string> requestTokens)
{
    bool isValidCommand = false;
    std::string argument1 = "", argument2 = "";
    if (requestTokens.size() > 1)
        argument1 = requestTokens[1];

    if (requestTokens.size() > 2)
        argument2 = requestTokens[2];

    if (controller->isValidCommand(requestTokens[0]))
    {
        if (requestTokens.size() <= 3 && controller->isValidArgument(argument1, argument2))
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

std::string CommandParser::getResponse()
{
    return controller->getResponse();
}