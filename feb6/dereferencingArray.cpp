#include<iostream>

int main(){
    int* arr=new int[5];
    for(int index=0;index<5;index++){
        *(arr+index)=index*10;
    }
    for(int index=0;index<5;index++){
        std::cout<<*(arr+index)<<std::endl;
    }

    // for(int index=0;index<5;index++){
    //     std::cout<<*(*(arr+index)+index)<<std::endl;
    // }
}