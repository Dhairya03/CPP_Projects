#include<iostream>

class Animal{
    protected:
    int speed{};
    public: 
    void print(){
        std::cout<<speed<<std::endl;
    }
};

class Cat:public Animal{
    public:
    void print(){
        speed=20;
        std::cout<<speed<<std::endl;
    }
};

class Dog:public Animal{
    public:
    void print(){
        speed=40;
        std::cout<<speed<<std::endl;
    }
};

int main(){
    Cat c;
    c.print();
    Dog d;
    d.print();
}