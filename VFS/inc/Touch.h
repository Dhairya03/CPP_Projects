#ifndef TOUCH_H
#define TOUCH_H

#include <ICommand.h>
#include <FileSystem.h>

class Touch : public ICommand
{
        std::string path;
public:
    Touch(const std::string &);
    void execute(std::shared_ptr<Directory> currentDirectory) override;
};
#endif

// first create a filesystemcomponent that is file and store its parent , and store it in vector
//  print message of file creation