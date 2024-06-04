#include <iostream>
#include <CommandParser.h>

int main()
{
    CommandParser *parser=new CommandParser();
    std::string request;
    do
    {
        std::cout << "Enter the command " << std::endl;
        getline(std::cin, request);
        std::cout << "Request entered is : " << request << std::endl;
        if (parser->parseRequest(request))
        {
            if (parser->validateCommand(request))
            {
            }
            else
            {
                std::cout << "command not found" << std::endl;
            }
        }
        else
        {
            continue;
        }
    } while (request != "quit");
    return 0;
}