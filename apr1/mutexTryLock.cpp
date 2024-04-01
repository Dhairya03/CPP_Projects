#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Times()
{
    for (int i = 0; i < 100000; ++i)
    {
        if (mtx.try_lock()) //it tries to lock if it is not possible it returns otherwise locks does not wait for it to get free and lock the resource
        {
            ++counter;
            mtx.unlock();
        }
    }
}

int main()
{
    std::thread t1(increaseTheCounterFor100000Times);
    std::thread t2(increaseTheCounterFor100000Times);
    t1.join();
    t2.join();
    std::cout << "Counter could increase upto : " << counter << std::endl;

    return 0;
}