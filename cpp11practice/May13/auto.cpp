#include <iostream>

auto fun(int a, int b)
{
    return a + b;
}

auto &fun2()
{
    int a = 5;
    int b = 10;
    int &c = a;
    //&c=b;
    return c;
}

int main()
{
    auto a = 'a';
    a = 56;
    std::cout << a << std::endl;
    a = fun(20, 14);
    std::cout << a << std::endl;

    auto y = fun2();
    std::cout << typeid(y).name() << std::endl;
    std::cout << y << std::endl;
}