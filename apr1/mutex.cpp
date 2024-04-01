#include <iostream>
#include <thread>
#include <mutex>
int myAmount = 0;
std::mutex m;

void addMoney()
{
    m.lock();
    ++myAmount; // critical section
    m.unlock();
}

int main()
{
    std::thread t1(addMoney); // no guarantee that t1 will lock first but whichever (t1 or t2) locks first then second will wait untill it is unlocked.
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout << myAmount << std::endl;
    return 0;
}