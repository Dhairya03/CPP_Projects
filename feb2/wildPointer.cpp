#include<iostream>
int main(){
    int *p;
    int *z= (int*)malloc(sizeof(int));;
    *p=12;
    std::cout<<p<<" "<<*p<<std::endl;
    std::cout<<z<<" "<<*z<<std::endl;
}