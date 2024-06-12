#include "Find.h"
#include <FileSystem.h>

Find::Find(const std::string &name) : name(name)
{
}

void Find::execute(FileSystem &fs)
{
    auto currentDirectory = fs.getCurrentDirectory();
    for (const auto &component : currentDirectory->listComponents())
    {
        if (component->getName() == name)
        {
            std::cout << "Found: " << component->getName() << " in " << currentDirectory->getName() << std::endl;
        }
    }
}