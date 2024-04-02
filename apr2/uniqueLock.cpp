#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopFor)
{
    std::unique_lock<std::mutex> lock(m1); // Automatically calls lock on mutex m1
    // Now no need to write lock and unlock
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }
    // Unlocking is happening in the destructor of unique_lock
}

void task2(const char *threadNumber, int loopFor)
{
    std::unique_lock<std::mutex> lock(m1, std::defer_lock); // Does not call lock on mutex m1 immediately, because used defer_lock
    lock.lock();                                            // But then we will have to explicitely tell to lock whenever we want to lock mutex m1
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }
    // lock.unlock(); is not needed as it will be unlocked in destructor of unique_lock.
}

int main()
{
    std::thread t1(task2, "T0", 10);
    std::thread t2(task2, "T1", 10);

    t1.join();
    t2.join();

    return 0;
}