#include <Ls.h>
#include <FileSystem.h>

void Ls::execute(FileSystem &fs)
{
    auto currentDir = fs.getCurrentDirectory();
    auto components = currentDir->listComponents();
    for (const auto &component : components)
    {
        std::cout << component->getName() << " ";
    }
    std::cout << std::endl;
}