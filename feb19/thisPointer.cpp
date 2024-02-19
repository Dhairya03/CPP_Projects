#include<iostream>

class Base{
    int a{};
    int b{};
    public:
    int setA(int val){
        a=val;
        return a;
    }
    void print(){
        std::cout<<this->a<<" "<<this->b<<std::endl;
    }
};

int main(){
    Base b;
    b.setA(5);
    b.print();
}