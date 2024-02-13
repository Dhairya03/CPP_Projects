#include<iostream>

class Base{
    static int s;
    public:
    // Base(){
    //     s=0;
    // }
    void setS(){
        s+=1;
    }
    void printS(){
        std::cout<<s<<std::endl;
    }
};
int main(){
    Base b1;
    Base b2;
    b1.printS();
    // b2.printS();
    // b2.setS();
    // b2.printS();
    // b1.printS();
}