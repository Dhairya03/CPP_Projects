#include <Rm.h>
#include <FileSystem.h>

Rm::Rm(const std::string &path) : path(path) {}

std::string Rm::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDir = fs.getCurrentDirectory();
    auto file = currentDir->findComponent(path);

    if (file && file->getType() == "File")
    {
        currentDir->removeComponent(file);
        response = "File removed: " + path + "\n";
    }
    else
    {
        response = "File not found: " + path + "\n";
    }
    return response;
}