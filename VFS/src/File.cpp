#include <File.h>

void File::setContent(const std::string data)
{
    std::cout << "setContent" << std::endl;
    this->content = data;
}

std::string File::getContent() const
{
    std::cout << "getContent" << std::endl;
    return content;
}
