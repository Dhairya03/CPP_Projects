#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopFor)
{
    std::lock_guard<std::mutex> lock(m1);
    //lockguard is a class that controls the ownership within a scope and releases in the destructor.
    // Now no need to write lock and unlock
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }
    // Unlocking is happening in the destructor of lock_guard
}

int main()
{
    std::thread t1(task, "T0", 10);
    std::thread t2(task, "T1", 10);

    t1.join();
    t2.join();

    return 0;
}