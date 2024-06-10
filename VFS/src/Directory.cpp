#include "Directory.h"
#include <algorithm>

Directory::Directory(const std::string &name) : IDirectory(name) {}

std::string Directory::getName() const
{
    return name;
}

std::string Directory::getType() const
{
    return "Directory";
}

std::string Directory::getPath() const
{
    return name;
}

void Directory::addComponent(std::shared_ptr<FileSystemComponent> component)
{
    for (auto c : components)
    {
        std::cout << "components" << c << std::endl;
    }
    components.push_back(component);
    std::cout << "addCompoennt" << &components << std::endl;
    // for (auto c : components)
    // {
    //     std::cout << c << std::endl;
    // }
}

void Directory::removeComponent(std::shared_ptr<FileSystemComponent> component)
{
    components.erase(std::remove(components.begin(), components.end(), component), components.end());
}

std::shared_ptr<FileSystemComponent> Directory::findComponent(const std::string &name)
{
    for (const auto &component : components)
    {
        if (component->getName() == name)
        {
            return component;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<FileSystemComponent>> Directory::listComponents() const
{
    std::cout << "list";
    std::cout << "insidelistcompoennts" << &components << std::endl;
    for (auto c : components)
    {
        std::cout << c << std::endl;
    }
    return components;
}

Directory::~Directory()
{
}
