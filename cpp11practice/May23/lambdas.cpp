#include <iostream>
#include <vector>

// void printVector(int value)
// {
//     std::cout << "Value" << value << std::endl;
// }

void iterate(std::vector<int> &values, void (*func)(int))
{
    for (int v : values)
    {
        func(v);
    }
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    // iterate(v, printVector);
    iterate(v, [](int value)
            { std::cout << "Value " << value << std::endl; });
}