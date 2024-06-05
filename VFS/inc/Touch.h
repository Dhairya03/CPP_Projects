#ifndef TOUCH_H
#define TOUCH_H

#include <ICommand.h>

class Touch : public ICommand
{
public:
    void execute() override;
};
#endif