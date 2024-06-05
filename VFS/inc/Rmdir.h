#ifndef RMDIR_H
#define RMDIR_H

#include <ICommand.h>

class Rmdir : public ICommand
{
public:
    void execute() override;
};
#endif