#include <File.h>

File::File(const std::string &name) : IFile(name) {}

void File::setContent(const std::string data)
{
    std::cout << "setContent" << std::endl;
    std::cout << data << " " << content << std::endl;
    content = data;
}

std::string File::getContent() const
{
    std::cout << "getContent" << std::endl;
    return content;
}
