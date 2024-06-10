#ifndef VI_H
#define VI_H

#include <ICommand.h>

class Vi : public ICommand
{
    std::string path;

public:
    Vi(const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};

#endif