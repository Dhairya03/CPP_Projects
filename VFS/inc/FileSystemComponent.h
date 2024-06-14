#ifndef FILE_SYSTEM_COMPONENT_H
#define FILE_SYSTEM_COMPONENT_H

#include <IFileSystemComponent.h>
#include <memory>

class FileSystemComponent : public IFileSystemComponent
{
protected:
    std::string name;

public:
    FileSystemComponent();
    FileSystemComponent(const std::string &);
    std::string getName() const;
    std::string getType() const;
};

#endif