#ifndef I_COMMAND_H
#define I_COMMAND_H

#include <iostream>
class IFileSystem;

class ICommand
{
public:
    virtual std::string execute(IFileSystem &) = 0;
};

#endif