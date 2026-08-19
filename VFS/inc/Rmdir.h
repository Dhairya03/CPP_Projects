#ifndef RMDIR_H
#define RMDIR_H

#include "ICommand.h"
class IFileSystem;

class Rmdir : public ICommand
{
    std::string path;

public:
    Rmdir(const std::string &);
    std::string execute(IFileSystem &) override;
};
#endif
