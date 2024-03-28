#include <iostream>
#include <thread>

static bool isFinished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals;
    while (!isFinished)
    {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

void DoWorkTwo()
{
    using namespace std::literals::chrono_literals;
    while (!isFinished)
    {
        std::cout << "Working two..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(DoWork);

    std::thread worker2(DoWorkTwo);

    std::cin.get();
    isFinished = true;
    worker.join();
    worker2.join();
    std::cout << "Finished" << std::endl;
    std::cin.get();
}