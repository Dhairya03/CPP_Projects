#include <iostream>
#include <thread>

static bool isFinished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals;
    while (!isFinished)
    {
        std::cout << "Working..." << std::endl;
        // std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(DoWork);
    while(1){
        std::cout<<"In main"<<std::endl;
    }
    std::cin.get();
    isFinished = true;
    worker.join();
    std::cout << "Finished" << std::endl;
    std::cin.get();
}