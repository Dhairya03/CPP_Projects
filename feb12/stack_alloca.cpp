#include<iostream>
#include<stdio.h>
#include<alloca.h>

int main(){

    int* dataptr=NULL;
    dataptr=(int*)alloca(40);
    int *dataptr2=NULL;
    dataptr2=(int*)alloca(sizeof(int)*5);

    int*dataptr3=NULL;
        dataptr3=(int*)malloc(sizeof(int)*5);

int *dataptr4=NULL;
    dataptr4=(int*)alloca(sizeof(int)*50);

    int*dataptr5=NULL;
        dataptr5=(int*)malloc(sizeof(int)*50);


    for(int i=0;i<5;i++){
        std::cout<<&dataptr2[i]<<std::endl;
    }
    std::cout<<dataptr2<<std::endl;
    std::cout<<&dataptr2<<std::endl;
    std::cout<<dataptr<<std::endl;
    std::cout<<&dataptr<<std::endl;
    std::cout<<&dataptr3<<std::endl;
    std::cout<<dataptr3<<std::endl;
    free(dataptr3);
    free(dataptr5);
   // free(dataptr);
    std::cin.get();
}