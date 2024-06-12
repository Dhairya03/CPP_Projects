#ifndef LS_H
#define LS_H

#include <ICommand.h>
class FileSystem;

class Ls : public ICommand
{
public:
    void execute(FileSystem &) override;
};

#endif
