#include <Mkdir.h>

Mkdir::Mkdir(const std::string &path) : path(path) {}

void Mkdir::execute(std::shared_ptr<Directory> currentDir)
{
    std::cout << "Mkdir current"<<currentDir << std::endl;

    if (currentDir->findComponent(path))
    {
        std::cout << "Directory already exists: " << path << std::endl;
    }
    else
    {
        currentDir->addComponent(std::make_shared<Directory>(path));
        std::cout << "Directory created: " << path << std::endl;
    }
}
