#include<iostream>

int main(){
    int arr[5]={1,2,4,4,5};
    std::cout<<arr<<std::endl;
std::cout<<*arr<<std::endl;
std::cout<<arr+2<<std::endl;
std::cout<<*(arr+2)<<std::endl;
std::cout<<*(arr)+2<<std::endl;
//std::cout<<*(0x7ffe48173fb8)<<std::endl;
// std::cout<<arr<<std::endl;
// std::cout<<arr<<std::endl;
// std::cout<<arr<<std::endl;
// std::cout<<arr<<std::endl;

// int var=10;
// float *ptr=&var;
// std::cout<<*ptr<<std::endl;

int *ptr;
std::cout<<ptr<<" "<<*ptr<<std::endl;

int *ptr1=NULL;
std::cout<<ptr1<<" "<<std::endl;

    return 0;
}