#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2{9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> v3(6);
    copy(v1.begin(), v1.begin() + 3, v2.begin());
    for (int i = 0; i < v2.size(); i++)
    {
        std::cout << v2[i];
    }

    copy_n(v1.begin(), 4, v3.begin());
    for (int i = 0; i < v3.size(); i++)
    {
        std::cout << v3[i];
    }
}