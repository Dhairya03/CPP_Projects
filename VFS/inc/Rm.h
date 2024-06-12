#ifndef RM_H
#define RM_H

#include <ICommand.h>
class FileSystem;

class Rm : public ICommand
{
    std::string path;

public:
    Rm(const std::string &);
    void execute(FileSystem &) override;
};

#endif