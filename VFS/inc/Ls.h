#ifndef LS_H
#define LS_H

#include <ICommand.h>

class Ls : public ICommand
{
public:
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};

#endif


//list the children of current directory 