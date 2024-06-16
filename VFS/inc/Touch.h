#ifndef TOUCH_H
#define TOUCH_H

#include "ICommand.h"
class IFileSystem;

class Touch : public ICommand
{
    std::string path;

public:
    Touch(const std::string &);
    std::string execute(IFileSystem &) override;
};
#endif
