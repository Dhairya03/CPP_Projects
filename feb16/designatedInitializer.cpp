#include<iostream>

struct init
{
    int a;
    int b;
    int c;
};

int main(){
    init i1{.a{1},.c{2}};
    std::cout<<i1.a<<" "<<i1.b<<" "<<i1.c<<std::endl;
    init i2{.a=1,.c=2};
        std::cout<<i2.a<<" "<<i2.b<<" "<<i2.c<<std::endl;
    //init i3{.b{1},.a{2}};
      //  std::cout<<i3.a<<" "<<i3.b<<" "<<i3.c<<std::endl;


}
