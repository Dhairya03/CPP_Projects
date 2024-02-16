#include<iostream>

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    Rectangle r1{1,2};
    const Rectangle r2{3,4};
    std::cout<<r1.breadth<<" "<<r1.length<<std::endl;
    std::cout<<r2.breadth<<" "<<r2.length<<std::endl;
    r1.length=5;
    //r2.length=6;
      std::cout<<r1.breadth<<" "<<r1.length<<std::endl;
    std::cout<<r2.breadth<<" "<<r2.length<<std::endl;
}