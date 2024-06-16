#include "CommandController.h"
#include "constants.h"

CommandController::CommandController(IFileSystem *fs) : fs(fs)
{
}

bool CommandController::isValidCommand(const std::string &command)
{
    bool isCommandValid = false;
    this->command = command;
    for (auto cmd : commandsToString)
    {
        if (this->command == cmd.second)
        {
            isCommandValid = true;
        }
    }
    return isCommandValid;
}

bool CommandController::isValidArgument(const std::string &argument1, const std::string &argument2)
{
    bool isValidArgument = false;
    if (command == "ls" || command == "exit")
    {
        if (argument1 == "" && argument2 == "")
            isValidArgument = true;
    }
    else if (command == "mv")
    {
        if (argument1 == "" || argument2 == "")
            isValidArgument = false;
        else
            isValidArgument = true;
    }
    else if (command == "vi")
    {
        if (argument1 != "" || argument2 == "")
        {
            isValidArgument = true;
            std::string data;
            std::cout << "Enter data for file " << argument1 << ": ";
            std::getline(std::cin, data);
            this->argument2 = data;
        }
        else
        {
            isValidArgument = false;
        }
    }
    else
    {
        if (argument1 != "" && argument2 == "")
            isValidArgument = true;
        else
            isValidArgument = false;
    }
    if (isValidArgument == true)
    {
        this->argument1 = argument1;
        if (command != "vi")
            this->argument2 = argument2;
    }
    return isValidArgument;
}

void CommandController::executeCommand()
{
    if (command != "exit")
    {
        fs->setCommand(command, argument1, argument2);
        setResponse(fs->executeCommand());
    }
    else
    {
        setResponse("Exiting from file system");
    }
}

void CommandController::setResponse(std::string res)
{
    response = res;
}

std::string CommandController::getResponse()
{
    return response;
}