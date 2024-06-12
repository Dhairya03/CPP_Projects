#ifndef FIND_H
#define FIND_H

#include <ICommand.h>
class FileSystem;

class Find : public ICommand
{
    std::string name;

public:
    Find(const std::string &);
    void execute(FileSystem &) override;
};
#endif
