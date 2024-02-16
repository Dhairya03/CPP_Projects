#include<iostream>

struct Base
{
    Base(){
        std::cout<<"constructor"<<std::endl;
    }
    ~Base(){
        std::cout<<"Destructor"<<std::endl;
    }
};

struct Child:public Base{
    Child(){
        std::cout<<"Child Constructor"<<std::endl;
    }
    ~Child(){
        std::cout<<"Child destructor"<<std::endl;
    }
};
int main(){
    Child c;
    std::cout<<"base struict"<<std::endl;
    Base b;
    std::cout<<"end base"<<std::endl;
    return 0;
}
