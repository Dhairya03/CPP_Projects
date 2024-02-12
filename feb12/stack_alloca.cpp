#include<iostream>
#include<stdio.h>
#include<alloca.h>

int main(){

    int* dataptr=NULL;
    dataptr=(int*)alloca(50);
    std::cout<<dataptr<<std::endl;
    std::cout<<&dataptr<<std::endl;
    std::cin.get();
}