#include <Mkdir.h>
#include <FileSystem.h>

Mkdir::Mkdir(const std::string &path) : path(path) {}

void Mkdir::execute(FileSystem &fs)
{
    // std::cout << "Mkdir current"<<currentDir << std::endl;
    auto currentDir = fs.getCurrentDirectory();
    if (currentDir->findComponent(path))
    {
        std::cout << "Directory already exists: " << path << std::endl;
    }
    else
    {
        currentDir->addComponent(std::make_shared<Directory>(path,fs.getCurrentDirectory()));
        std::cout << "Directory created: " << path << std::endl;
    }
}
