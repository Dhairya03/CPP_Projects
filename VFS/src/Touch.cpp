#include <Touch.h>
#include <File.h>

Touch::Touch(const std::string &path) : path(path) {}

void Touch::execute(std::shared_ptr<Directory> currentDir)
{
    // auto currentDir = fs.getCurrentDirectory();
    auto file = std::dynamic_pointer_cast<File>(currentDir->findComponent(path));
    if (!file)
    {
        file = std::make_shared<File>(path);
        currentDir->addComponent(file);
        std::cout << "New file created: " << path << std::endl;
    }
    else
    {
        std::cout << "File already exists: " << path << std::endl;
    }
}