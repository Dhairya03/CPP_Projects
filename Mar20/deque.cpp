#include <iostream>
#include <deque>

int main()
{
    std::deque<int> deq;
    for (int i = 0; i < 5; i++)
    {
        deq.push_back(i);
        deq.push_front(i + 5);
    }
    for (int i = 0; i < deq.size(); i++)
    {
        std::cout << deq.at(i) << std::endl;
        std::cout << deq[i] << std::endl;
    }
}