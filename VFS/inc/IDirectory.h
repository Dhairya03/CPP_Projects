#ifndef I_DIRECTORY_H
#define I_DIRECTORY_H

#include <FileSystemComponent.h>

class IDirectory : public FileSystemComponent
{
public:
    virtual void addComponent() = 0;
    virtual void removeComponent() = 0;
    virtual void findComponent() = 0;
    virtual void listComponent() = 0;
};

#endif