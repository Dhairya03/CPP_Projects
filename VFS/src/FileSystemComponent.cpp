#include <FileSystemComponent.h>

FileSystemComponent::FileSystemComponent() {}

FileSystemComponent::FileSystemComponent(const std::string &name) : name(name)
{
}

std::string FileSystemComponent::getName() const
{
    return name;
}

std::string FileSystemComponent::getType() const
{
    return "";
}