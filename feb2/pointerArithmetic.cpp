#include<iostream>

int main(){
    int arr[]={10,20,30,45,67,56,74};
    int *j,*i;

    i=&arr[1];
    j=&arr[5];

    std::cout<<arr[8]<<std::endl;
    std::cout<<j<<" "<<i<<std::endl;
    std::cout<<j-i<<" "<<*j-*i<<std::endl; //why j-i is giving 4 when it should give 16.
    std::cout<<sizeof(arr)<<" "<<sizeof(arr[1])<<std::endl;

}