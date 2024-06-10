#ifndef I_FILE_H
#define I_FILE_H

#include <FileSystemComponent.h>

class IFile : public FileSystemComponent
{
public:
    IFile(const std::string &);
    virtual std::string getContent() const = 0;
    virtual void setContent(const std::string) = 0;
};

#endif