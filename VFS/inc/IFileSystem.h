#ifndef I_FILE_SYSTEM_H
#define I_FILE_SYSTEM_H

#include <iostream>
#include <memory>
#include <Directory.h>

class IFileSystem
{
public:
    virtual std::shared_ptr<Directory> getCurrentDirectory() const = 0;
    virtual void setCurrentDirectory(std::shared_ptr<Directory>) = 0;
    virtual void setCommand(const std::string &, const std::string &, const std::string &) = 0;
    virtual void executeCommand() = 0;
    virtual ~IFileSystem() ;
};

#endif