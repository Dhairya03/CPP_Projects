#ifndef MKDIR_H
#define MKDIR_H

#include <ICommand.h>
#include <FileSystem.h>

class Mkdir : public ICommand
{
        std::string path;
public:
    Mkdir(const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};
#endif

// create a filesystemcomponent that is directory. decalre its parent and push it in vector.
// print message of directory creation