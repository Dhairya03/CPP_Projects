#include <Rm.h>

Rm::Rm(const std::string &path) : path(path) {}

void Rm::execute(std::shared_ptr<Directory> currentDir)
{
    // auto currentDir = fs.getCurrentDirectory();
    auto file = currentDir->findComponent(path);
    if (file && file->getType() == "File")
    {
        currentDir->removeComponent(file);
        std::cout << "File removed: " << path << std::endl;
    }
    else
    {
        std::cout << "File not found: " << path << std::endl;
    }
}