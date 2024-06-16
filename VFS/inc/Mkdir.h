#ifndef MKDIR_H
#define MKDIR_H

#include "ICommand.h"
class IFileSystem;

class Mkdir : public ICommand
{
    std::string path;

public:
    Mkdir(const std::string &);
    std::string execute(IFileSystem &) override;
};
#endif
