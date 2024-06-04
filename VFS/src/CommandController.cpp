#include <CommandController.h>
#include <constants.h>

CommandController::CommandController(std::string command, std::string argument1, std::string argument2) : command(command), argument1(argument1), argument2(argument2)
{
}

bool CommandController::isValidCommand()
{
    for (auto cmd : commandsToString)
    {
        if (command == commandsToString[cmd])
        {
            std::cout << "valid command" << command << " " << commandsToString[cmd] << std::endl;
        }
    }
}
