#include<iostream>
int main(){

    int a=10;
    char c='a';

    void *p=&a;
    std::cout<<p<<" "<<(int*)p<<std::endl;
    p=&c;
    std::cout<<p<<" "<<*(char*)p<<std::endl;

    int arr[]={1,2};
    void *ptr=&arr;
    std::cout<<arr<<std::endl;
    ptr=(int*)ptr+1;
    std::cout<<ptr<<" "<<*(int*)ptr<<std::endl;
}