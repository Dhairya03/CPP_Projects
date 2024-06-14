#include "Find.h"
#include <FileSystem.h>

Find::Find(const std::string &name) : name(name)
{
}

std::string Find::execute(IFileSystem &fs)
{
    std::string response = "";
    bool isFound = false;
    auto currentDirectory = fs.getCurrentDirectory();
    for (const auto &component : currentDirectory->listComponents())
    {
        if (component->getName() == name)
        {
            isFound = true;
            response = "Found: " + component->getName() + " in " + currentDirectory->getName() + "\n";
        }
    }
    if (!isFound)
    {
        response = name + "not found.\n";
    }
    return response;
}