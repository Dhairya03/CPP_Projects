#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
using namespace std::chrono;

bool counter = true;
std::mutex m;
void func()
{
    // m.lock();
    while (counter)
    {
        counter = false;
        std::this_thread::sleep_for(1s);
    }
}

void func2()
{
    // m.lock();
    while (!counter)
    {
        counter = true;
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread t1(func);
    std::this_thread::sleep_for(1ms);

    std::thread t2(func2);

    t1.join();
    t2.join();
    return 0;
}