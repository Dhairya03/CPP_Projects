#include<iostream>

class Base {
   
    public:
     int* x=new int;
    Base(){
        std::cout<<"Construcor"<<std::endl;
    }
    // void deleteObject(){
    //     delete x;
    // }
    ~Base(){
        // delete x;
        std::cout<<"Destructor"<<std::endl;
    }
};

// void func(){
//     Base b;
//     std::cout<<b.x<<std::endl;
//     b.~Base();
//     std::cout<<b.x<<std::endl;

// }

int main(){
    //func();
    Base b;
    std::cout<<b.x<<std::endl;
    // b.deleteObject();
    b.~Base();
    std::cout<<b.x<<std::endl;
    return 0;
}