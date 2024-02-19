#include<iostream>

class Base{
    int x;
    public:
    Base(){
        std::cout<<"Default"<<std::endl;
    }
    Base(Base& b){
        std::cout<<"Copy"<<std::endl;

    }
    Base add(Base b){
        std::cout<<"Inside add"<<std::endl;
        return b;
    }
    Base operator+(Base b){
        std::cout<<"operator"<<std::endl;
        Base res;
        res.x=x+b.x;
        std::cout<<"added"<<std::endl;
        return res;
    }

};

int main(){
Base b1;
std::cout<<"copy b1 and b2"<<std::endl;
Base b2=b1;
std::cout<<"calling add fucntion"<<std::endl;
b1.add(b2);
std::cout<<"Called"<<std::endl;
Base b3=b1+b2;
std::cout<<"Temp"<<std::endl;

}