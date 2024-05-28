#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::recursive_timed_mutex m1;

void fun1(int n)
{
    auto timeout_time = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
    if (m1.try_lock_until(timeout_time))
    {
        std::cout << "fun1 " << n << std::endl;
        if (n > 0)
        {
            fun1(n - 1);
        }
        m1.unlock();
    }
    else
    {
        std::cout << "fun1 could not acquire lock" << std::endl;
    }
}

void fun2(int n)
{
    if (m1.try_lock_for(std::chrono::milliseconds(1000)))
    {
        std::cout << "fun2 " << n << std::endl;
        if (n > 0)
        {
            fun2(n - 2);
        }
        m1.unlock();
    }
    else
    {
        std::cout << "fun2 could not acquire lock" << std::endl;
    }
}

int main()
{
    std::thread t1(fun1, 1000000);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::thread t2(fun2, 100);

    std::cout << "Main" << std::endl;

    t1.join();
    t2.join();
    return 0;
}
