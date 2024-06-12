#ifndef TOUCH_H
#define TOUCH_H

#include <ICommand.h>
class FileSystem;

class Touch : public ICommand
{
    std::string path;

public:
    Touch(const std::string &);
    void execute(FileSystem &) override;
};
#endif
