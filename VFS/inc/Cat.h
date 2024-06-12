#ifndef CAT_H
#define CAT_H

#include <ICommand.h>
class FileSystem;

class Cat : public ICommand
{
    std::string path;

public:
    Cat(const std::string &);
    void execute(FileSystem &) override;
};

#endif