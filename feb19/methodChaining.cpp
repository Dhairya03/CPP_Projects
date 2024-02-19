#include<iostream>

class Calc{
    int value;
    public:
    Calc& add(int val){
        value+=val;
        return *this ;
    }

    Calc& sub(int  val){
        value-=val;
        return *this;
    }

    Calc& mul(int val){
        value*=val;
        return *this;
    }

    int getValue(){
        return value;
    }

};

int main(){
    Calc c{};
    c.add(3).sub(2).mul(5);
    std::cout<<c.getValue();
}