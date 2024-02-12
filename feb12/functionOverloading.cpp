#include<iostream>
int add(int a,int b){
    std::cout<<"int";
    return a+b;
}

double add(double a,double b){
    std::cout<<"double";
    return a+b;
}

int main(){
    std::cout<<add(1,2)<<std::endl;
    std::cout<<add(0.1,0.2)<<std::endl;
    std::cout<<add('a',false)<<std::endl;
    
}