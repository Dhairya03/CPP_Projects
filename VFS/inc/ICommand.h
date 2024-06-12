#ifndef I_COMMAND_H
#define I_COMMAND_H

#include <iostream>
class FileSystem;

class ICommand
{
public:
    virtual void execute(FileSystem &) = 0;
};

#endif