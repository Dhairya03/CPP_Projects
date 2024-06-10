#ifndef I_DIRECTORY_H
#define I_DIRECTORY_H

#include <FileSystemComponent.h>
#include <vector>

class IDirectory : public FileSystemComponent
{
public:
    virtual ~IDirectory();
    IDirectory(const std::string& name);
    virtual void addComponent(std::shared_ptr<FileSystemComponent> component) = 0;
    virtual void removeComponent(std::shared_ptr<FileSystemComponent> component) = 0;
    virtual std::shared_ptr<FileSystemComponent> findComponent(const std::string &name) = 0;
    virtual std::vector<std::shared_ptr<FileSystemComponent>> listComponents() const = 0;
};

#endif