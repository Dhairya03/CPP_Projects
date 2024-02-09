#include <iostream>

class Base
{
    int a, b, c;

public:
    void setValue(int x, int y)
    {
        a = x;
        b = y;
    }
    int *getAddressA()
    {
        return &a;
    }
    int *getAddressB()
    {
        return &b;
    }
    int *getAddressC()
    {
        return &c;
    }
    int getSum()
    {
        int x1 = 10;
        std::cout<<&x1<<std::endl;
        printf("the address is %p\n", &Base::getSum);
        std::cout << &Base::getSum << std::endl;
        return a + b;
    }
    // Base::int(*ptr)()=&getSum;
};

int main()
{
    Base b;
    std::cout << sizeof(b) << std::endl;
    b.setValue(5, 10);
    std::cout << b.getSum() << std::endl;
    Base *ptr = &b;
    std::cout << ptr->getSum() << std::endl;
    // int(*ptr)()=&(b.getSum);
    std::cout << b.getAddressA() << " " << b.getAddressB() << " " << b.getAddressC() << std::endl;
    std::cout << sizeof(b) << std::endl;

    return 0;
}