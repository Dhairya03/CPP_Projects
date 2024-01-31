#include<iostream>

int main(){
    int i=3;
    std::cout<<"Address of i : "<<&i<<std::endl;
    int* s=&i;
    //float *f=&i;
    int **p=&s;
    std::cout<<"Pointer to &i (printing s): "<<s<<"(printing *s)"<<*s<<std::endl;

// address can be fetched by & or pointer
    std::cout<<"Adress of i"<<&i<<" "<<s<<" "<<*p<<std::endl;
    std::cout<<"Adress of s"<<&s<<std::endl;
    //value can be fetched by these ways.
    std::cout<<"value of i"<<i<<" "<<*s<<" "<<*(&i)<<std::endl;
    std::cout<<"value of s"<<s<<std::endl;


    return 0;
}