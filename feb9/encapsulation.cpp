#include<iostream>

class Base{
    int x;
    public:
        void setX(int a){
            x=a;
        }
        int printX(){
            return x;
        }
};

int main(){
    Base b;
    b.setX(10);
    std::cout<<b.printX()<<std::endl;

}