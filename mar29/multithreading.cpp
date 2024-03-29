#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <numeric>
using namespace std::chrono;

void AccumulateRange(unsigned long long &sum, unsigned long long start, unsigned long long end)
{
    sum = 0;
    for (unsigned long long i = start; i < end; i++)
    {
        sum += i;
    }
}

int main()
{
    int numThreads = 10;
    unsigned long long numElements = 1000000000;
    unsigned long long step = numElements / numThreads;
    std::vector<std::thread> threads;
    std::vector<unsigned long long> partialSum(numThreads);

    auto startTime = high_resolution_clock::now();

    for (int i = 0; i < numThreads; i++)
    {
        threads.push_back(std::thread(AccumulateRange, std::ref(partialSum[i]), i * step, (i + 1) * step));
    }

    for (std::thread &t : threads)
    {
        if (t.joinable())
            t.join();
    }
    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime - startTime);

    unsigned long long total = std::accumulate(partialSum.begin(), partialSum.end(), 0);
    std::cout << "total:" << total << std::endl;
    std::cout << "time " << duration.count() / 1000000 << std::endl;

    return 0;
}