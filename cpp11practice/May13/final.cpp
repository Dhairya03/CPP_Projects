#include <iostream>

class Base // final
{
public:
    int a;

    virtual void fun() //final //cannot be overridden  as it is marked final
    {
        std::cout << "Hello" << std::endl;
    }
};
class Derived : public Base // cannot derive from Base as it is marked final
{
public:
    int b;
    void fun()
    {
        std::cout << "Hi" << std::endl;
    }
};
int main()
{
    Base *b;
    Derived d;
    b = &d;
    b->fun();
}