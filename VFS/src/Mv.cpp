#include <Mv.h>

Mv::Mv(const std::string &src, const std::string &dest) : src(src), dest(dest) {}

void Mv::execute(std::shared_ptr<Directory> currentDir)
{
    // auto currentDir = fs.getCurrentDirectory();
    auto file = currentDir->findComponent(src);
    if (file)
    {
        file->getPath() = dest;
        currentDir->removeComponent(file);
        auto newDir = std::dynamic_pointer_cast<Directory>(currentDir->findComponent(dest));
        if (newDir)
        {
            newDir->addComponent(file);
        }
        else
        {
            currentDir->addComponent(file);
        }
        std::cout << "Moved " << src << " to " << dest << std::endl;
    }
    else
    {
        std::cout << "File/Directory not found: " << src << std::endl;
    }
}
