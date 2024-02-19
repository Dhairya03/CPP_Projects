#include<iostream>

class Base{
    public: 
    // Base(Base &b){
    //     std::cout<<"Copy"<<std::endl;
    // }
    virtual void print(){
        std::cout<<"Base"<<std::endl;
    }
};

class Derived:public Base{
    public:
    virtual void print(){
        std::cout<<"Derived"<<std::endl;
    }
};

int main(){
    Derived d;
    Base &ref{d};
    ref.print();
}