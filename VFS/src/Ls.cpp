#include <Ls.h>

void Ls::execute(std::shared_ptr<Directory> currentDir)
{
    // auto currentDir = fs.getCurrentDirectory();
    std::cout << "LsCuurent" << currentDir << std::endl;
    auto components = currentDir->listComponents();
    for (const auto &component : components)
    {
        std::cout << component->getName() << " ";
    }
    std::cout << std::endl;
}