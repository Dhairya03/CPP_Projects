#include <iostream>

class Base
{
public:
    void print()
    {
        std::cout << "base" << std::endl;
    }

    // virtual void print()
    // {
    //     std::cout << "base" << std::endl;
    // }

    // virtual void print()=0;

    // virtual void print();
};

class Dervied1 : public Base
{
public:
    void print()
    {
        std::cout << "Derived one " << std::endl;
    }
};

class Derived2 : public Base
{
public:
    void print()
    {
        std::cout << "Derived two" << std::endl;
    }
};

int main()
{
    Base *b;
    b->print();
    // Dervied1 d1;
    // Derived2 d2;
    b->print();
    // b=&d1;
    // b->print();
    // b=&d2;
    // b->print();
    return 0;
}
