#ifndef FIND_H
#define FIND_H

#include <ICommand.h>

class Find : public ICommand
{
public:
    void execute() override;
};
#endif