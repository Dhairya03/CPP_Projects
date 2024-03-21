#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int arr[5]={45,80,20,34,10};
    std::sort(arr,arr+5);
    for(int i=0;i<5;i++){
        std::cout<<arr[i]<<std::endl;
    }
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::sort(vec.begin(), vec.end());
    // std::sort(vec.end(), vec.begin()); //segmentation fault
    std::reverse(vec.begin(), vec.end());
    std::reverse(vec.end(), vec.begin());//why no segmentation fault 

    for (int i : vec)
    {
        std::cout << i;
    }
}