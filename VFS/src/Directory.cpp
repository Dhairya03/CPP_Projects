#include "Directory.h"
#include <algorithm>

Directory::Directory(const std::string &name, std::shared_ptr<Directory> parent) : IDirectory(name), parent(parent)
{
}

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
    components.push_back(component);
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
    return components;
}

Directory::~Directory()
{
}

std::shared_ptr<Directory> Directory::getParent()
{
    return parent;
}