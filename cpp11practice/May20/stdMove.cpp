#include <iostream>
class Base
{
public:
    Base() { std::cout << "Created" << std::endl; }
    Base(Base &b) { std::cout << "Copied" << std::endl; }
    Base(Base &&b) { std::cout << "Moved" << std::endl; }
};

int main()
{
    std::string a = "hello";
    std::cout << "a " << a << std::endl;
    std::string b = std::move(a);
    std::cout << "a " << a << " b " << b << std::endl; //here a="" because move constructor is called of string class

    int x = 10;
    std::cout << x << std::endl;
    int y = std::move(x);
    std::cout << x << " " << y << std::endl; //here x=10. y=10 

    Base b1;
    Base c = b1;
    Base d = std::move(b1); //here move constructor is called

    return 0;
}