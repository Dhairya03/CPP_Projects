#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::chrono;

int x = 1;
std::mutex m;
void increment(int n)
{
    if (m.try_lock())
    {
        while (n--)
        {
            x++;
        }
        m.unlock();
    }
}

int main()
{
    auto startTime = high_resolution_clock::now();

    std::thread t1(increment, 20000000);
    std::thread t2(increment, 10000000);

    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    std::cout << x << std::endl;
    std::cout << "time " << duration.count() / 1000000 << std::endl;
    return 0;
}