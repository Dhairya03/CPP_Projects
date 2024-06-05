#ifndef FILE_H
#define FILE_H

#include <IFile.h>

class File : public IFile
{
    std::string content;

public:
    void setContent(const std::string) override;
    std::string getContent() const override;
};
#endif