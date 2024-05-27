#include <iostream>

void func(int)
{
    std::cout << "integer" << std::endl;
}
void func(int *)
{
    std::cout << "pointer" << std::endl;
}
void func(bool)
{
    std::cout << "boolean" << std::endl;
}
auto function1()
{
    return NULL;
}

auto function2()
{
    return nullptr;
}

int main()
{

    // func(NULL); // creates ambiguity
    // it converts implicitly to all data types //it is also comparable to all pointer types

    // if (/*  (void*)  */ function1() == function2()) // cannot be equated as one is null and other is nullptr;
        {//void* is used to compare the two...
            std::cout << "null equal to nullptr" << std::endl;
        }
        else
        {
            std::cout << "null not equal to nullptr" << std::endl;
        }

//hardware control of cpp
        // char *p;
        // char *p = (char *)0x12345678;
        // *p = 0x55233333;
        // std::cout << p << std::endl;
        return 0;
}
