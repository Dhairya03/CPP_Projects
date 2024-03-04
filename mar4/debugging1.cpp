#include <iostream>
// #define ENABLE_DEBUG

int add(int a, int b)
{
#ifdef ENABLE_DEBUG
    std::cerr << "add():x" << a << std::endl;
    std::cerr << "add():y" << b << std::endl;
#endif
    return a-b;
}

int main()
{
    int x, y;
    std::cout << "Enter input x" << std::endl;
    std::cin >> x;
#ifdef ENABLE_DEBUG
    std::cerr << "main():x" << x << std::endl;
#endif
    std::cout << "Enter input y" << std::endl;
    std::cin >> y;
#ifdef ENABLE_DEBUG
    std::cerr << "main():y" << y << std::endl;
#endif
    std::cout << add(x, y) << std::endl;
    return 0;
}