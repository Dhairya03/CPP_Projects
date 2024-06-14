#ifndef LS_H
#define LS_H

#include <ICommand.h>
class IFileSystem;

class Ls : public ICommand
{
public:
    std::string execute(IFileSystem &) override;
};

#endif
