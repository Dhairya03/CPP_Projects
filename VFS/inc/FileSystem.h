#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <IFileSystem.h>
#include <Directory.h>
#include <ICommand.h>

class FileSystem : public IFileSystem
{
    std::shared_ptr<IDirectory> root;
    std::shared_ptr<IDirectory> currentDirectory;
    std::unique_ptr<ICommand> command;

public:
    FileSystem(std::shared_ptr<IDirectory>);
    std::shared_ptr<IDirectory> getCurrentDirectory() const;
    void setCurrentDirectory(std::shared_ptr<IDirectory>);
    std::string executeCommand();
    void setCommand(const std::string &, const std::string &, const std::string &);
};

#endif