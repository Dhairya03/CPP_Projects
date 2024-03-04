#include<iostream>

int func3(){
    int func3Variable=25;
    std::cout<<func3Variable<<std::endl;
    return 0;
}

int func2(){
    int func2Variable=20;
    std::cout<<func2Variable<<std::endl;
    func3();
    return 0;
}

int func1(){
    int func1Variable=15;
    std::cout<<func1Variable<<std::endl;
    func2();
    return 0;
}

int main(){
    int variable=10;
    std::cout<<variable<<std::endl;
    func1();
    return 0;
}