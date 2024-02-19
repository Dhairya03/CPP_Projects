#include<iostream>

class Base{
    int x,y;
    public:
    Base(){
        x=0;
        y=0;
    }
    Base(int a,int b){
        x=a;
        y=b;
    }
    void print(){
        std::cout<<x<<" "<<y<<std::endl;
    }

};

int main(){
    Base b(2,4);
    b.print();

}