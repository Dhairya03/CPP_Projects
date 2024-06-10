#include <Vi.h>
#include <memory>
#include <File.h>

Vi::Vi(const std::string &path) : path(path) {}

void Vi::execute(std::shared_ptr<Directory> currentDir)
{
    std::string data;
    std::cout << "Enter data for file " << path << ": ";
    std::getline(std::cin, data);
    if (data != "q")
    {
        auto file = std::dynamic_pointer_cast<File>(currentDir->findComponent(path));
        if (!file)
        {
            file = std::make_shared<File>(path);
            currentDir->addComponent(file);
            std::cout << "New file created: " << path << std::endl;
        }
        file->setContent(data);
        std::cout << "Data saved to file: " << path << std::endl;
    }
    else
    {
        std::cout << "File not created" << std::endl;
    }
}
