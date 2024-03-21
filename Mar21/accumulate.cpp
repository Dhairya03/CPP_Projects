#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>
#include <numeric>

int main()
{
    std::ifstream input("data.txt");
    std::multiset<int> values;
    int currValue;
    while (input >> currValue)
        values.insert(currValue);
    // double total = 0.0;
    // for (std::multiset<int>::iterator itr = values.begin();
    //      itr != values.end(); ++itr)
    //     total += *itr;
    // std::cout << "Average is: " << total / values.size() << std::endl;

    std::cout << accumulate(values.begin(), values.end(), 0.0) / values.size() << std::endl;
    
    // Internal implememtation of accumulate
    // template <typename InputIterator, typename Type>
    // Type accumulate(InputIterator start, InputIterator end, Type initial)
    // {
    //     while (start != end)
    //     {
    //         initial += *start;
    //         ++start;
    //     }
    //     return initial;
    // }
}