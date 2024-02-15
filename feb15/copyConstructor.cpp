#include<iostream>

class Base{
    int x,y;
    public:
    Base(){
        x=1;y=1;
        std::cout<<"Default constructor"<<std::endl;
    }
    int setX(int value){
        x=value;
        return x;
    }
    Base(Base& b){
        x=b.x;
        y=b.y;
        std::cout<<"Copy constructor called"<<std::endl;
    }
        void print(){
            std::cout<<x+y<<std::endl;
        }

};

int main(){
    Base b1;
Base b2=b1;
b1.print();
b2.print();
b2.setX(5);
b1.print();
b2.print();


}