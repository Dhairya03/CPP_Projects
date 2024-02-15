#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "Constructro A" << std::endl;
    }
    ~A()
    {
        std::cout << "Destructro A" << std::endl;
    }
};
class B : public A
{
public:
    B()
    {
        std::cout << "Constructro B" << std::endl;
    }
    ~B()
    {
        std::cout << "Destructor B" << std::endl;
    }
};
class C : public B
{
public:
    C()
    {
        B();//destrcuted as sson as it returns
        std::cout << "Constructro C" << std::endl;
    }
    ~C()
    {
        std::cout << "Destructor C" << std::endl;
    }
};

int main()
{
    C c;
    return 0;
}