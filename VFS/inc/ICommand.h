#ifndef I_COMMAND_H
#define I_COMMAND_H

#include <iostream>
#include <FileSystemComponent.h>
#include <Directory.h>

class ICommand
{
    // FileSystemComponent *component;

public:
    virtual void execute(std::shared_ptr<Directory> currentDirectory) = 0;
};

#endif