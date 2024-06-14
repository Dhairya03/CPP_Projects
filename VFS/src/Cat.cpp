#include <Cat.h>
#include <File.h>
#include <FileSystem.h>

Cat::Cat(const std::string &path) : path(path) {}

std::string Cat::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDir = fs.getCurrentDirectory();
    auto file = std::dynamic_pointer_cast<File>(currentDir->findComponent(path));
    if (file)
    {
        response = "File contents of " + path + ": " + file->getContent() + "\n";
    }
    else
    {
        response = "File not found: " + path + "\n";
    }
    return response;
}