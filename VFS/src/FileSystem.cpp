#include "FileSystem.h"
#include "Mv.h"
#include "Touch.h"
#include "Find.h"
#include "Mkdir.h"
#include "Rm.h"
#include "Rmdir.h"
#include "Ls.h"
#include "Cat.h"
#include "Cd.h"
#include "Vi.h"

FileSystem::FileSystem(std::shared_ptr<IDirectory> root):root(root)
{
    currentDirectory = root;
}

std::shared_ptr<IDirectory> FileSystem::getCurrentDirectory() const
{
    return currentDirectory;
}

void FileSystem::setCurrentDirectory(std::shared_ptr<IDirectory> directory)
{
    currentDirectory = directory;
}

void FileSystem::setCommand(const std::string &comm, const std::string &path, const std::string &dest)
{
    std::string src = path;
    if (comm == "mkdir")
    {
        this->command = std::make_unique<Mkdir>(path);
    }
    else if (comm == "ls")
    {
        this->command = std::make_unique<Ls>();
    }
    else if (comm == "cat")
    {
        this->command = std::make_unique<Cat>(path);
    }
    else if (comm == "rmdir")
    {
        this->command = std::make_unique<Rmdir>(path);
    }
    else if (comm == "vi")
    {
        this->command = std::make_unique<Vi>(path, dest);
    }
    else if (comm == "cd")
    {
        this->command = std::make_unique<Cd>(path);
    }
    else if (comm == "rm")
    {
        this->command = std::make_unique<Rm>(path);
    }
    else if (comm == "touch")
    {
        this->command = std::make_unique<Touch>(path);
    }
    else if (comm == "find")
    {
        this->command = std::make_unique<Find>(path);
    }
    else if (comm == "mv")
    {
        this->command = std::make_unique<Mv>(src, dest);
    }
    else
    {
        std::cout << "Unknown command: " << comm << std::endl;
        this->command = nullptr;
    }
}

std::string FileSystem::executeCommand()
{
    return command->execute(*this);
}
