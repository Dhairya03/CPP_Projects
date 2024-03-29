#include <iostream>
#include <thread>
#include <chrono>

void fun(int n)
{
    while (n--)
    {
        std::cout << "hello " << n << std::endl;
    }
}

int main()
{
    std::thread t1(fun, 20);
    std::cout << "main" << std::endl;
    
    t1.detach();
    // if double detach is used the program crashes but it is printing the thread while it was not when single detach is used.
    if (t1.joinable())
        t1.detach();
    std::cout << "after detach" << std::endl;
    if (t1.joinable())
        t1.join();
    return 0;
}