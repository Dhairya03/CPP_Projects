#include <iostream>
#include <memory> // for std::unique_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    std::unique_ptr<Resource> res = std::make_unique<Resource>(); // if we use make_unique then we dont need to use new;

    return 0;
} // res goes out of scope here, and the allocated Resource is destroyed //no delete is used