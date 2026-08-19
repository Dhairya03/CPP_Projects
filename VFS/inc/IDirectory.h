#ifndef I_DIRECTORY_H
#define I_DIRECTORY_H

#include "FileSystemComponent.h"
#include <vector>

class IDirectory : public FileSystemComponent
{
public:
    virtual ~IDirectory();
    IDirectory(const std::string &name);
    virtual std::shared_ptr<IDirectory> getParent() = 0;
    virtual void addComponent(std::shared_ptr<IFileSystemComponent> component) = 0;
    virtual void removeComponent(std::shared_ptr<IFileSystemComponent> component) = 0;
    virtual std::shared_ptr<IFileSystemComponent> findComponent(const std::string &name) = 0;
    virtual std::vector<std::shared_ptr<IFileSystemComponent>> listComponents() const = 0;
};

#endif