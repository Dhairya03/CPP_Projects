#include <iostream>

int main()
{
    int *ptr = (int *)malloc(5);
    int *ptr1 = (int *)malloc(1);
    std::cout << ptr << " " << *ptr << std::endl;
    std::cout << ptr1 << " " << *ptr1 << std::endl;

    //free(ptr);
    std::cout << ptr << " " << *ptr << std::endl;
    std::cout << ptr1 << " " << *ptr1 << std::endl;

    delete ptr;
    delete ptr1;
    std::cout << ptr << " " << *ptr << std::endl;
    std::cout << ptr1 << " " << *ptr1 << std::endl;
}