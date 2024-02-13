#include<iostream>
#include<stdio.h>
#include<alloca.h>

int main(){

    int* dataptr=NULL;
    dataptr=(int*)alloca(40);
    int *dataptr2=NULL;
    dataptr2=(int*)alloca(sizeof(int)*5);
    for(int i=0;i<5;i++){
        std::cout<<&dataptr2[i]<<std::endl;
    }
    std::cout<<dataptr2<<std::endl;
    std::cout<<&dataptr2<<std::endl;
    std::cout<<dataptr<<std::endl;
    std::cout<<&dataptr<<std::endl;
   // free(dataptr);
    std::cin.get();
}