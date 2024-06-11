#include <File.h>

File::File(const std::string &name) : IFile(name) {}

void File::setContent(const std::string data)
{
    content = data;
}

std::string File::getContent() const
{
    return content;
}
