#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

void func(int n)
{
    int *p;
    while (n--)
    {
        std::cout << *p << std::endl;
    }
    *p++;
}

int main()
{
    std::thread t1(func, 10000);
    t1.detach();
    return 0;
}