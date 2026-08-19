#include "Touch.h"
#include "File.h"
#include "FileSystem.h"

Touch::Touch(const std::string &path) : path(path) {}

std::string Touch::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDir = fs.getCurrentDirectory();
    auto file = std::dynamic_pointer_cast<IFile>(currentDir->findComponent(path));
    if (!file)
    {
        file = std::make_shared<File>(path);
        currentDir->addComponent(file);
        response = "New file created: " + path + "\n";
    }
    else
    {
        response = "File already exists: " + path + "\n";
    }
    return response;
}