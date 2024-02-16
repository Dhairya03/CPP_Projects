#include<iostream>

class Base{
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

};

int main(){
Base b1;
std::cout<<"copy b1 and b2"<<std::endl;
Base b2=b1;
std::cout<<"calling add fucntion"<<std::endl;
b1.add(b2);
std::cout<<"Called"<<std::endl;

}