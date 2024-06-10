#include <CommandController.h>
#include <constants.h>

CommandController::CommandController(FileSystem *fs, std::string command, std::string argument1, std::string argument2) : fs(fs), command(command), argument1(argument1), argument2(argument2)
{
    // fs = new FileSystem();
}

bool CommandController::isValidCommand()
{
    bool isCommandValid = false;
    for (auto cmd : commandsToString)
    {
        if (command == cmd.second)
        {
            isCommandValid = true;
            std::cout << "valid command" << std::endl;
        }
    }
    return isCommandValid;
}

bool CommandController::isValidArgument()
{
    // need to be a valid string
    if (argument1 != argument2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CommandController::executeCommand()
{
    // fs->setCommand();
    // fs->command->execute();
    // fs->executeCommand(command);
    fs->setCommand(command, argument1, argument2);
    fs->executeCommand();
}

void CommandController::setResponse(std::string res)
{
    response = res;
}
