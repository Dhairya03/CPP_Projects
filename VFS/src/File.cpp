#include "File.h"

File::File(const std::string &name) : IFile(name) {}

std::string File::getType() const
{
    return "File";
}

void File::setContent(const std::string data)
{
    content = data;
}

std::string File::getContent() const
{
    return content;
}

std::shared_ptr<IDirectory> File::getParent()
{
    return parent;
}