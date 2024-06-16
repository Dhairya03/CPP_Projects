#include "Mkdir.h"
#include "FileSystem.h"

Mkdir::Mkdir(const std::string &path) : path(path) {}

std::string Mkdir::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDir = fs.getCurrentDirectory();
    if (currentDir->findComponent(path))
    {
        response = "Directory already exists: " + path + "\n";
    }
    else
    {
        currentDir->addComponent(std::make_shared<Directory>(path, fs.getCurrentDirectory()));
        response = "Directory created: " + path + "\n";
    }
    return response;
}
