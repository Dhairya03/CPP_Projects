#include <iostream>
#include <CommandParser.h>

int main()
{
    FileSystem *fs = new FileSystem();
    CommandParser *parser = new CommandParser(fs);

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
                // std::cout << parser->getResponse() << std::endl;
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
    } while (request != "exit");
    return 0;
}