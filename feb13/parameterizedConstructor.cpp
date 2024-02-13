#include<iostream>

class Base{
    int x;
    public:
    Base(int a,int b){
        x=a+b;
    }
    
    int print(){
        //std::cout<<x<<std::endl;
        return x;
    }

};

int main(){
    Base b(4,5);
    std::cout<<b.print()<<std::endl;
    return 0;

}
