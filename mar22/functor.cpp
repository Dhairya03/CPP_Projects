#include <iostream>
#include <algorithm>

class increment
{
private:
    int num;
public:
    increment(int n) : num(n) { }
    //overloading of () operator
    //functors can keep the state of variables
    
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 5;
 
    std::transform(arr, arr+n, arr, increment(to_add));
 
    for (int i=0; i<n; i++)
        std::cout << arr[i] << " ";
}