#include <iostream>
#include <CommandParser.h>
#include <CommandController.h>
#include <FileSystem.h>
#include <Directory.h>

int main()
{
    auto root = std::make_shared<Directory>("/", nullptr);
    FileSystem *fs = new FileSystem(root);
    CommandController *controller = new CommandController(fs);
    CommandParser *parser = new CommandParser(controller);

    std::string request;
    do
    {
        std::cout << "Enter the command " << std::endl;
        std::cout << fs->getCurrentDirectory()->getName() << ">";
        getline(std::cin, request);
        std::cout << "Request entered is : " << request << std::endl;
        auto requestTokens = parser->parseRequest(request);

        if (parser->validateCommand(requestTokens))
        {
            std::cout << parser->getResponse() << std::endl;
        }
        else
        {
            std::cout << "command not found" << std::endl;
        }

    } while (request != "exit");
    return 0;
}