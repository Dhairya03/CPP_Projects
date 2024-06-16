#ifndef MV_H
#define MV_H

#include "ICommand.h"
class IFileSystem;

class Mv : public ICommand
{
private:
    std::string src;
    std::string dest;

public:
    Mv(const std::string &, const std::string &);
    std::string execute(IFileSystem &) override;
};

#endif