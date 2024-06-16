#ifndef VI_H
#define VI_H

#include "ICommand.h"
class IFileSystem;

class Vi : public ICommand
{
    std::string path;
    std::string data;

public:
    Vi(const std::string &, const std::string &);
    std::string execute(IFileSystem &) override;
};

#endif