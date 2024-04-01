#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
int x = 0;
std::mutex m;
void func(int n)
{
    m.lock();
    while (n--)
    {
        m.lock();
        x++;
        m.unlock();
    }
    m.unlock();
}

int main()
{
    std::thread t1(func, 100000000);
    std::thread t2(func, 200000000);
    t1.join();
    t2.join();
    std::cout << x << std::endl;
    return 0;
}