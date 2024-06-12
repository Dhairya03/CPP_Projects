#include <FileSystemComponent.h>

FileSystemComponent::FileSystemComponent(const std::string &name) : name(name)
{
}

std::string FileSystemComponent::getName() const
{
    return name;
}

std::string FileSystemComponent::getPath() const
{
    return path;
}

std::string FileSystemComponent::getType() const
{

}