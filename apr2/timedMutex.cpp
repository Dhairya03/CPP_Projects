#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int myAmount = 0;
std::timed_mutex m;

void incrementFor(int i)
{
    if (m.try_lock_for(std::chrono::seconds(2))) // if 1 sec then any one thread coudn't enter
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Thread " << i << " entered" << std::endl;
        m.unlock();
    }
    else
    {
        std::cout << "Thread " << i << " coudn't enter" << std::endl;
    }
}

void incrementUntil(int i)
{
    auto now = std::chrono::steady_clock::now();
    if (m.try_lock_until(now + std::chrono::seconds(2)))
    {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Thread " << i << " entered" << std::endl;
        m.unlock();
    }
    else
    {
        std::cout << "Thread " << i << " coudn't enter" << std::endl;
    }
}

int main()
{
    // std::thread t1(incrementFor, 1); // no guarantee that t1 will lock first but whichever (t1 or t2) locks first then second will wait untill it is unlocked.
    // std::thread t2(incrementFor, 2);
    //  t1.join();
    //  t2.join();

    std::thread t3(incrementUntil, 1);
    std::thread t4(incrementUntil, 2);
    t3.join();
    t4.join();

    std::cout << myAmount << std::endl;
    return 0;
}