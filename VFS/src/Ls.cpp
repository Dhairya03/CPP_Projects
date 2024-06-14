#include <Ls.h>
#include <FileSystem.h>

std::string Ls::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDir = fs.getCurrentDirectory();
    auto components = currentDir->listComponents();
    for (const auto &component : components)
    {
        response += component->getName() + " ";
    }
    response += "\n";
    return response;
}