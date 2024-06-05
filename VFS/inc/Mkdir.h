#ifndef MKDIR_H
#define MKDIR_H

#include <ICommand.h>

class Mkdir : public ICommand
{
public:
    void execute() override;
};
#endif