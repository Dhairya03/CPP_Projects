#include <iostream>
#include <algorithm>
#include <vector>

bool IsEven(int value)
{
    return value % 2 == 0;
}

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    //count_if counts only when the condition is satisfied
    //takes a boolean function that return whether condition is true or not
    std::cout << count_if(v1.begin(), v1.end(), IsEven) << std::endl;

    //fill the conatiner with the same value
    fill(v1.begin(), v1.end(), 0);
    std::cout << count_if(v1.begin(), v1.end(), IsEven) << std::endl;

    //fill upto n elements in the container
    std::fill_n(v1.begin(), 10, 0);
    std::cout << count_if(v1.begin(), v1.end(), IsEven) << std::endl;
}