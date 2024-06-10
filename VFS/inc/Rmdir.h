#ifndef RMDIR_H
#define RMDIR_H

#include <ICommand.h>

class Rmdir : public ICommand
{
    std::string path;

public:
    Rmdir(const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};
#endif

// make its parent null and remove it from vector(erase).
// free the memory