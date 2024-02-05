#include<iostream>

// int add(int size,int arr[][size]){
//     return 0;
// }

// int main(){
//     int size;
//     std::cin>>size;
//     int arr[size][size];
//     add(size,arr);
// }
void print(int m, int n, int arr[][3])
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf("%d ", arr[i][j]);
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3, n = 3;
    print(m, n, arr);
    return 0;
}