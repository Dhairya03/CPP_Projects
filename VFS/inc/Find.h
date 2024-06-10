#ifndef FIND_H
#define FIND_H

#include <ICommand.h>

class Find : public ICommand
{
    std::string name;
public:
    Find(const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};
#endif

// list the current directory and match the srgument with them
// if found return true statement ither wise false statement.