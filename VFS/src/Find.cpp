#include "Find.h"

Find::Find(const std::string &name) : name(name)
{
}

void Find::execute(std::shared_ptr<Directory> currentDirectory)
{
    for (const auto &component : currentDirectory->listComponents())
    {
        if (component->getName() == name)
        {
            std::cout << "Found: " << component->getName() << " in " << currentDirectory->getName() << std::endl;
        }
    }
}