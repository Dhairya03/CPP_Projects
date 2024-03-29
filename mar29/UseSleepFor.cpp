#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono;
bool isLoop = true;
void fun()
{
    int count = 0;
    while (isLoop)
    {
        count++;
        std::cout << "Looping..." << std::endl;
        std::this_thread::sleep_for(1ms);
    }
    std::cout << count << std::endl;
}

int main()
{
    std::thread t1(fun);

    std::this_thread::sleep_for(1s);

    isLoop = false;
    t1.join();
    return 0;
}