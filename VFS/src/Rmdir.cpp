#include "Rmdir.h"
#include "FileSystem.h"

Rmdir::Rmdir(const std::string &path) : path(path)
{
}

std::string Rmdir::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDirectory = fs.getCurrentDirectory();
    auto component = currentDirectory->findComponent(path);
    if (!component)
    {
        response = "Directory not found: " + path + "\n";
    }
    else
    {
        auto dir = std::dynamic_pointer_cast<IDirectory>(component);
        if (!dir)
        {
            response = "Path is not a directory: " + path + "\n";
        }
        else if (!dir->listComponents().empty())
        {
            response = "Directory is not empty: " + path + "\n";
        }
        else
        {
            currentDirectory->removeComponent(component);
            response = "Directory removed: " + path + "\n";
        }
    }
    return response;
}