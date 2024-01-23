#include<iostream>
#define AND &&
#define CONDITION (a>25 AND a<50)
int main(){
    int a=30;
    if(CONDITION) std::cout<<"In Condition range"<<std::endl;
    else std::cout<<"Out of Condition range"<<std::endl;
}