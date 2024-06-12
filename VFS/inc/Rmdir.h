#ifndef RMDIR_H
#define RMDIR_H

#include <ICommand.h>
class FileSystem;

class Rmdir : public ICommand
{
    std::string path;

public:
    Rmdir(const std::string &);
    void execute(FileSystem &) override;
};
#endif
