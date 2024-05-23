#include <iostream>
#include <memory>

class Base
{
public:
    Base(int value) : data(value)
    {
        std::cout << "Base created with value: " << data << std::endl;
    }

    ~Base()
    {
        std::cout << "Base destroyed with value: " << data << std::endl;
    }

    int data;
};

int main()
{
    std::shared_ptr<Base> sp = std::make_shared<Base>(42);

    std::weak_ptr<Base> wp = sp;
    
    sp.reset();

    if (!wp.expired()) //can check if any shred pointer has ownership or not
    {
        std::cout << "The value stored in shared:" << (*wp.lock()).data << std::endl;
    }
    // std::cout << "The value stored in shared:" << (*wp.lock()).data << std::endl; //gives seg fault as sp is reset

    return 0;
}
