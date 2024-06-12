#ifndef MKDIR_H
#define MKDIR_H

#include <ICommand.h>
class FileSystem;

class Mkdir : public ICommand
{
    std::string path;

public:
    Mkdir(const std::string &);
    void execute(FileSystem &) override;
};
#endif
