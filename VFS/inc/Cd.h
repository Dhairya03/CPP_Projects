#ifndef CD_H
#define CD_H

#include "ICommand.h"
class IFileSystem;

class Cd : public ICommand
{
    std::string path;

public:
    Cd(const std::string &);
    std::string execute(IFileSystem &fs) override;
};

#endif