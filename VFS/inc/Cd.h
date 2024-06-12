#ifndef CD_H
#define CD_H

#include <ICommand.h>
class FileSystem;

class Cd : public ICommand
{
    std::string path;

public:
    Cd(const std::string &);
    void execute(FileSystem &fs) override;
};

#endif