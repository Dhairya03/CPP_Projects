#include <iostream>
#include <vector>

class MyClass
{
public:
    int value;

    MyClass(int val) : value(val)
    {
        std::cout << "Constructor called for " << value << std::endl;
    }

    MyClass(const MyClass &other) : value(other.value)
    {
        std::cout << "Copy constructor called for " << value << std::endl;
    }

    MyClass(MyClass &&other) noexcept : value(std::move(other.value))
    {
        std::cout << "Move constructor called for " << value << std::endl;
    }

    ~MyClass()
    {
        std::cout << "My Class destroyed" << value << std::endl;
    }
};

int main()
{
    MyClass m1(1);
    MyClass m2(2);

    std::vector<MyClass> myVector;
    std::vector<MyClass> Vector;
    std::cout << &myVector[0] << std::endl;

    myVector.emplace_back(1);
    // myVector.push_back(1);
    std::cout << &myVector[0] << std::endl;

    myVector.emplace_back(m2);
    std::cout << &myVector[0] << std::endl;

    // myVector.emplace_back(m2);
    // std::cout << &myVector[0] << std::endl;

    // myVector.emplace_back(m2);
    // std::cout << &myVector[0] << std::endl;
    // myVector.emplace_back(1);
    // myVector.emplace_back(2);

    // std::cout << &Vector[0] << std::endl;
    // Vector.push_back(1);
    // std::cout << &Vector[0] << std::endl;

    // Vector.push_back(2);
    // Vector.push_back(m1);
    // Vector.push_back(m2);

    return 0;
}