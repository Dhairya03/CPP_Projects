#ifndef FILE_SYSTEM_COMPONENT_H
#define FILE_SYSTEM_COMPONENT_H

#include <IFileSystemComponent.h>

class FileSystemComponent : public IFileSystemComponent
{
    std::string componentName;
    std::string componentPath;
    FileSystemComponent *parent;

public:
    std::string getName() const;
    std::string getPath() const;
};

#endif