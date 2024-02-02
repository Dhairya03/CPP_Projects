#include<iostream>

// int *func(){
//     int x=5;
//     return &x;
// }

int main(){
    // int *p=func();
    // std::cout<<*p<<" "<<std::endl;

    int*ptr;
    {
        int a=10;
        ptr=&a;
    }
    std::cout<<*ptr<<" " << ptr<<std::endl;

}