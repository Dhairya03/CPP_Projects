#include "Rmdir.h"

Rmdir::Rmdir(const std::string &path) : path(path)
{
}

void Rmdir::execute(std::shared_ptr<Directory> currentDirectory)
{
    auto component = currentDirectory->findComponent(path);
    if (!component)
    {
        std::cout << "Directory not found: " << path << std::endl;
        return;
    }

    auto dir = std::dynamic_pointer_cast<IDirectory>(component);
    if (!dir)
    {
        std::cout << "Path is not a directory: " << path << std::endl;
        return;
    }

    if (!dir->listComponents().empty())
    {
        std::cout << "Directory is not empty: " << path << std::endl;
        return;
    }

    currentDirectory->removeComponent(component);
    std::cout << "Directory removed: " << path << std::endl;
}