#include<iostream>

int main(){
    int a=5;
    int *p;
    std::cout<<a<<std::endl;
    std::cout<<*p<<std::endl;
    p=&a;
    std::cout<<*p<<std::endl;
    return 0;

}