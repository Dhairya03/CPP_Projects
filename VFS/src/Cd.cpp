#include <Cd.h>
#include <FileSystem.h>
#include <sstream>

std::vector<std::string> splitPath(const std::string &path)
{
    std::vector<std::string> parts;
    std::stringstream ss(path);
    std::string part;
    while (std::getline(ss, part, '/'))
    {
        if (!part.empty())
        {
            parts.push_back(part);
        }
    }
    return parts;
}

Cd::Cd(const std::string &path) : path(path) {}

void Cd::execute(FileSystem &fs)
{
    auto currentDir = fs.getCurrentDirectory();

    if (path.empty())
    {
        std::cout << "Invalid path" << std::endl;
        return;
    }

    std::vector<std::string> parts = splitPath(path);
    std::shared_ptr<Directory> targetDirectory = currentDir;

    for (const auto &part : parts)
    {
        if (part == "..")
        {
            if (auto parent = targetDirectory->getParent())
            {
                targetDirectory = parent;
            }
            else
            {
                std::cout << "Already at the root directory" << std::endl;
                return;
            }
        }
        else if (part == ".")
        {
            continue; // Current directory, no action needed
        }
        else
        {
            auto component = targetDirectory->findComponent(part);
            if (!component || component->getType() != "Directory")
            {
                std::cout << "Directory not found: " << part << std::endl;
                return;
            }
            targetDirectory = std::dynamic_pointer_cast<Directory>(component);
        }
    }

    // Assuming there's a global file system object to set the current directory
    fs.setCurrentDirectory(targetDirectory);
    std::cout << "Changed to directory: " << targetDirectory->getName() << std::endl;

    // if (path == "..")
    // {

    // }
    // else
    // {
    //     auto dir = std::dynamic_pointer_cast<Directory>(currentDir->findComponent(path));
    //     if (dir)
    //     {
    //         fs.setCurrentDirectory(dir);
    //         std::cout << "Directory  found: " << path << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "Directory not found: " << path << std::endl;
    //     }
    // }
}
