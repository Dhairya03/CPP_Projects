#ifndef FILE_H
#define FILE_H

#include <IFile.h>
#include <Directory.h>
#include <sstream>

class File : public IFile
{
    std::string name;
    std::string content;
    std::shared_ptr<Directory> parent;

public:
    File(const std::string &name);
    void setContent(const std::string) override;
    std::string getContent() const override;
    std::shared_ptr<Directory> getParent();
};
#endif