#ifndef MV_H
#define MV_H

#include <ICommand.h>

class Mv : public ICommand
{
private:
    std::string src;
    std::string dest;

public:
    Mv(const std::string &, const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectoryfs) override;
};

#endif