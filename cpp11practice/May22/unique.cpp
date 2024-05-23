#include <iostream>

template <typename T>
class Unique_Pointer
{
    T *ptr = nullptr;

public:
    Unique_Pointer()
    {
        std::cout << "Pointer default created" << std::endl;
    }
    Unique_Pointer(T *new_ptr) : ptr(new_ptr)
    {
        std::cout << "Pointer created" << std::endl;
    }
    ~Unique_Pointer()
    {
        std::cout << "Pointer destroyed" << std::endl;
        delete ptr;
    }
    Unique_Pointer(Unique_Pointer &&other_ptr)
    {
        std::cout << "Move unique pointer" << std::endl;

        ptr = other_ptr.ptr;
        other_ptr.ptr = nullptr;
    }
    Unique_Pointer &operator=(Unique_Pointer &&other_ptr)
    {
        std::cout << "Move assignment pointer" << std::endl;
        if (this != &other_ptr)
        {
            delete ptr;
            ptr = other_ptr.ptr;
            other_ptr.ptr = nullptr;
        }
        return *this;
    }
    Unique_Pointer(const Unique_Pointer &) = delete;
    Unique_Pointer &operator=(const Unique_Pointer &) = delete;

    T *operator->()
    {
        return ptr;
    }
};
class Base
{

public:
    int value;

    Base(int val) : value(val)
    {
        std::cout << "Base created" << std::endl;
    }
    ~Base()
    {
        std::cout << "Base destroyed" << std::endl;
    }
};

int main()
{
    // Base *b1 = new Base(2);
    // Unique_Pointer<Base> p1(b1);
    Unique_Pointer<Base> p2(new Base(3));
    std::cout << p2->value << std::endl;

    p2->value = 4;

    std::cout << p2->value << std::endl;

    Unique_Pointer<Base> p3(std::move(p2));
    // std::cout << p2->value << std::endl;

    std::cout << p3->value << std::endl;
    Unique_Pointer<Base> p4;
    p4 = std::move(p3);
    std::cout << p4->value << std::endl;
}