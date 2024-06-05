#ifndef CD_H
#define CD_H

#include <ICommand.h>

class Cd : public ICommand
{
public:
    void execute() override;
};
#endif