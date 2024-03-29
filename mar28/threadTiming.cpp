#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std::chrono;
typedef unsigned long long ull;
ull OddSum = 0;
ull EvenSum = 0;

void findOddSum(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if ((i % 2) != 0)
        {
            OddSum += i;
        }
    }
}

void findEvenSum(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if ((i % 2) == 0)
        {
            EvenSum += i;
        }
    }
}

int main()
{
    ull start = 0;
    ull end =  190000000;

    auto startTime = high_resolution_clock::now();

    std::thread odd(findOddSum,start,end);
    std::thread even(findEvenSum,start,end);

//why the time after threading is more than when function is called
    // findEvenSum(start, end);
    // findOddSum(start, end);
    odd.join();
    even.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    std::cout << "odd sum " << OddSum << std::endl;
    std::cout << "even sum " << EvenSum << std::endl;
    std::cout << "time " << duration.count()/1000000 << std::endl;

    return 0;
}