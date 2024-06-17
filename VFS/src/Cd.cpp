#include "Cd.h"
#include "FileSystem.h"
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

std::string Cd::execute(IFileSystem &fs)
{
    std::string response = "";
    auto currentDir = fs.getCurrentDirectory();

    if (path.empty())
    {
        response = "Invalid path\n";
    }
    else
    {
        std::vector<std::string> parts = splitPath(path);
        std::shared_ptr<IDirectory> targetDirectory = currentDir;

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
                    response = "Already at the root directory\n";
                }
            }
            else if (part == ".")
            {
                continue;
            }
            else
            {
                auto component = targetDirectory->findComponent(part);
                if (!component || component->getType() != "Directory")
                {
                    response = "Directory not found: " + part + "\n";
                }
                else
                {
                    targetDirectory = std::dynamic_pointer_cast<IDirectory>(component);
                }
            }
        }

        fs.setCurrentDirectory(targetDirectory);
        response = "Changed to directory: " + targetDirectory->getName() + "\n";
    }

    return response;
}
