#ifndef CAT_H
#define CAT_H

#include <ICommand.h>
class IFileSystem;

class Cat : public ICommand
{
    std::string path;

public:
    Cat(const std::string &);
    std::string execute(IFileSystem &) override;
};

#endif