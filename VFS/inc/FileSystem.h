#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <IFileSystem.h>
#include <Directory.h>
#include <ICommand.h>

class FileSystem : public IFileSystem
{
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> currentDirectory;
    FileSystemComponent *component;
    std::unique_ptr<ICommand> command;

public:
    FileSystem();
    std::shared_ptr<Directory> getCurrentDirectory() const;
    void setCurrentDirectory(std::shared_ptr<Directory> directory);
    void executeCommand();
    void setCommand(const std::string &, const std::string &, const std::string &);
};

#endif