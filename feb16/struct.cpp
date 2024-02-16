#include<iostream>

struct Person{
    char ch;
    // int age=1;
    char id;
    

};


class Person1{
    public:
    char ch;
    int age=1;
   // int age2=1;
   // char id;
    double d;
    

};

int main(){
    Person p1;
    std::cout<<&p1<<std::endl;
    std::cout<<sizeof(p1)<<std::endl;
    std::cout<<sizeof(Person)<<std::endl;
    std::cout<<sizeof(p1.ch)<<sizeof(p1.id)<<std::endl;
    Person1 p2;
    std::cout<<&p2<<std::endl;
    std::cout<<sizeof(p2)<<std::endl;
    std::cout<<sizeof(Person1)<<std::endl;
    std::cout<<sizeof(p2.ch)<<sizeof(p2.d)<<sizeof(p2.age)<<std::endl;
    //std::cout<<p1.age<<std::endl;
    return 0;
}