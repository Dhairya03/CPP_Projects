#include <iostream>
#include <algorithm>

int main()
{
    int arr1[] = {1, 2, 3,5};
    int arr2[] = {4, 5, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int res[n];
    // for(int i=0;i<n;i++){
    //     res[i]=arr1[i]+arr2[i];
    // }

    std::transform(arr1, arr1 + n, arr2, res, std::plus<int>());

    for (int i = 0; i < n; i++)
    {
        std::cout << res[i];
    }
}