#ifndef FIND_H
#define FIND_H

#include "ICommand.h"
class IFileSystem;

class Find : public ICommand
{
    std::string name;

public:
    Find(const std::string &);
    std::string execute(IFileSystem &) override;
};
#endif
