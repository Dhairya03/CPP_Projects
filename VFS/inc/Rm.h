#ifndef RM_H
#define RM_H

#include "ICommand.h"
class IFileSystem;

class Rm : public ICommand
{
    std::string path;

public:
    Rm(const std::string &);
    std::string execute(IFileSystem &) override;
};

#endif