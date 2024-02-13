#include<iostream>

class Base{
    int x;
    public:
        Base(){
            x=1;
        }
        Base(Base& b){
            x=b.x +1;
        }
        void print(){
            std::cout<<x<<std::endl;
        }

};

int main(){
    Base b;
    Base b1(b);
    b.print();
    b1.print();
}