#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <IFileSystem.h>
#include <Directory.h>
#include <ICommand.h>

class FileSystem : public IFileSystem
{
    Directory *root;
    Directory *currentDirectory;
    FileSystemComponent *component;
    ICommand *command;

public:
    void setCommand();
    Directory *getCurrentDirectory();
};

#endif