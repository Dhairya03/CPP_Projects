#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <IDirectory.h>
#include <list>

class Directory : public IDirectory
{
    std::list<FileSystemComponent *> components;

public:
    void addComponent() override;
    void removeComponent() override;
    void findComponent() override;
    void listComponent() override;
};

#endif