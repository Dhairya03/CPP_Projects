#include <iostream>

void A(void *ptr)
{
    char *i = (char *)ptr;
    std::cout << *i << std::endl;
    std::cout << &i << std::endl;
}
int main()
{
    int x = 10;
    std::cout << &x;
    A(&x);
    std::cout << "\n" << std::endl;
    return 0;
}