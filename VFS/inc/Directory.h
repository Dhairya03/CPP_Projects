#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <IDirectory.h>
#include <list>
#include <vector>

class Directory : public IDirectory
{
private:
    std::vector<std::shared_ptr<FileSystemComponent>> components;
    std::shared_ptr<Directory> parent;

public:
    Directory(const std::string &name,std::shared_ptr<Directory>);
    std::string getName() const override;
    std::string getType() const override;
    std::string getPath() const override;
    std::shared_ptr<Directory> getParent();
    void addComponent(std::shared_ptr<FileSystemComponent> component);
    void removeComponent(std::shared_ptr<FileSystemComponent> component);
    std::shared_ptr<FileSystemComponent> findComponent(const std::string &name);
    std::vector<std::shared_ptr<FileSystemComponent>> listComponents() const;
    ~Directory();
};

#endif