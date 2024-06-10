#ifndef RM_H
#define RM_H

#include <ICommand.h>
#include <FileSystem.h>

class Rm : public ICommand
{
        std::string path;
public:
    Rm(const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};

#endif