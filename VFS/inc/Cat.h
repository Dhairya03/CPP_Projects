#ifndef CAT_H
#define CAT_H

#include <ICommand.h>
#include <FileSystem.h>

class Cat : public ICommand
{
    std::string path;

public:
    Cat(const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};

#endif