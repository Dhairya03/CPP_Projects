#include <Vi.h>
#include <memory>
#include <File.h>
#include <FileSystem.h>

Vi::Vi(const std::string &path, const std::string &data) : path(path), data(data) {}

std::string Vi::execute(IFileSystem &fs)
{
    std::string response;
    auto currentDir = fs.getCurrentDirectory();
    if (data != "q")
    {
        auto file = std::dynamic_pointer_cast<File>(currentDir->findComponent(path));
        if (!file)
        {
            file = std::make_shared<File>(path);
            currentDir->addComponent(file);
            response = "New file created: " + path + "\n";
        }
        file->setContent(data);
        response += "Data saved to file: " + path + "\n";
    }
    else
    {
        response = "File not created \n";
    }
    return response;
}
