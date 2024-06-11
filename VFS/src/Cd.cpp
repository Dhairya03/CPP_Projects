#include <Cd.h>

Cd::Cd(const std::string &path) : path(path) {}

void Cd::execute(std::shared_ptr<Directory> currentDir)
{
    if (path == "..")
    {
        
    }
    else
    {
        auto dir = std::dynamic_pointer_cast<Directory>(currentDir->findComponent(path));
        if (dir)
        {
            // fs.setCurrentDirectory(dir);
            // currentDir=dir;
        }
        else
        {
            std::cout << "Directory not found: " << path << std::endl;
        }
    }
}