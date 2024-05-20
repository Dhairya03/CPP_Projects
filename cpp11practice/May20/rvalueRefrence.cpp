#include <iostream>

int main()
{
    int x = 10;
    int z = 20;
    const int y = 10;
    int &ref = x;
    ref = z;
    std::cout << &x << &z << &ref << std::endl;
    std::cout << x << z << ref << std::endl;

    // int &ref2 = 10; // cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    // int &ref7 = y;  //binding reference of type ‘int&’ to ‘const int’ discards qualifiers
    const int &ref3 = x;
    const int &ref4 = 10;
    const int &ref9 = y;
    int &&ref5 = 10;
    ref5 = 11;
    // int &&ref6 = x; // cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    // int &&ref8 = y; //cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘const int’

    const int &&ref10 = 10;
}