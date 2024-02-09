#include<iostream>

class Car{
    protected:
    int id;
    char name[100];
    char type[4];

    public:
    void setValues(){
        std::cout<<"Enter id of car"<<std::endl;
        std::cin>>id;
        std::cout<<"Enter car name"<<std::endl;
        std::cin>>name;
        std::cout<<"Enter type of car: fast or slow"<<std::endl;
        std::cin>>type;
    }

    void print(){
        std::cout<<id<<" "<<name<<" "<<type<<std::endl;
    }
};

class FastCar:private Car{
    int speed;
    public:
    void getSpeed(){
        setValues();
        std::cout<<"Enter speed of car"<<std::endl;
        std::cin>>speed;
    }
    void display(){
        std::cout<<id<<" "<<name<<" "<<type<<" "<<speed<<std::endl;
    }
};

int main(){
    Car car;
    FastCar fcar;
    fcar.getSpeed();
    car.setValues();
    fcar.display();
    car.print();
}