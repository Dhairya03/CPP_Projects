#include <Rm.h>
#include <FileSystem.h>

Rm::Rm(const std::string &path) : path(path) {}

void Rm::execute(FileSystem &fs)
{
    auto currentDir = fs.getCurrentDirectory();
    auto file = currentDir->findComponent(path);
    // && file->getType() == "File"
    if (file )
    {
        currentDir->removeComponent(file);
        std::cout << "File removed: " << path << std::endl;
    }
    else
    {
        std::cout << "File not found: " << path << std::endl;
    }
}