#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <IDirectory.h>
#include <list>
#include <vector>

class Directory : public IDirectory
{
private:
    std::vector<std::shared_ptr<IFileSystemComponent>> components;
    std::shared_ptr<IDirectory> parent;

public:
    Directory(const std::string &name, std::shared_ptr<IDirectory>);
    std::string getName() const override;
    std::string getType() const override;
    std::shared_ptr<IDirectory> getParent() override;
    void addComponent(std::shared_ptr<IFileSystemComponent> component);
    void removeComponent(std::shared_ptr<IFileSystemComponent> component);
    std::shared_ptr<IFileSystemComponent> findComponent(const std::string &name);
    std::vector<std::shared_ptr<IFileSystemComponent>> listComponents() const;
    ~Directory();
};

#endif