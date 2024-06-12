#ifndef VI_H
#define VI_H

#include <ICommand.h>
class FileSystem;

class Vi : public ICommand
{
    std::string path;

public:
    Vi(const std::string &);
    void execute(FileSystem &) override;
};

#endif