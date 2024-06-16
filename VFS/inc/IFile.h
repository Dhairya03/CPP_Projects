#ifndef I_FILE_H
#define I_FILE_H

#include "FileSystemComponent.h"
#include "IDirectory.h"

class IFile : public FileSystemComponent
{
public:
    IFile(const std::string &);
    virtual std::string getContent() const = 0;
    virtual void setContent(const std::string) = 0;
    virtual std::shared_ptr<IDirectory> getParent() = 0;
};

#endif