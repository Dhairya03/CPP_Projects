#include <iostream>

class Base
{
    int a, b;

public:
    Base(int val) : a(val)
    {
        std::cout << "inside default" << a << std::endl;
        // Base();
    }

    Base(int v1, int v2) : Base(v1 + v2) // delegating constructor
    {
        std::cout << "Inside parameterized" << std::endl;
        // a = v1;
        // b = v2;
        // Base();
    }

    Base(int v1, int v2, int v3) : Base(v1 * v2, v3)
    {
    }
};

int main()
{

    // Base b1(1 + 2);
    Base b2(4, 5);
    Base b3(1, 2, 3);
}