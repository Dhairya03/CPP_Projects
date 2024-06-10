#include <Cat.h>
#include <File.h>

Cat::Cat(const std::string &path) : path(path) {}

void Cat::execute(std::shared_ptr<Directory> currentDir)
{
    // auto currentDir = fs.getCurrentDirectory();
    auto file = std::dynamic_pointer_cast<File>(currentDir->findComponent(path));
    // auto file=currentDir->findComponent(path);
    if (file)
    {
        std::cout << "File contents of " << path << ": " << file->getContent() << std::endl;
    }
    else
    {
        std::cout << "File not found: " << path << std::endl;
    }
}