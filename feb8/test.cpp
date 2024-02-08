#include<stdio.h>
#include<iostream>

// int main(){
//     int a;
//     scanf("%d",&a);
//     printf("%d\n",a);
//     char ch;
//     scanf("%c",&ch);
//     printf("%c",ch);
// }
int main(){
    // int a;
    // std::cin>>a;
    // std::cout<<a<<std::endl;
    // char ch;
    // std::cin>>ch;
    // std::cout<<ch<<std::endl;
    int arr[][2]={1,2,3,4};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}