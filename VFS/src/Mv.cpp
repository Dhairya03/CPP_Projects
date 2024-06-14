#include <Mv.h>
#include <FileSystem.h>

Mv::Mv(const std::string &src, const std::string &dest) : src(src), dest(dest) {}

std::string Mv::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDir = fs.getCurrentDirectory();
    auto file = currentDir->findComponent(src);
    if (file)
    {
        file->getName() = dest;
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
        response = "Moved " + src + " to " + dest + "\n";
    }
    else
    {
        response = "File/Directory not found: " + src + "\n";
    }
    return response;
}
