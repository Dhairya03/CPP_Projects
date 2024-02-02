#include <iostream>
#include <vector>

int main()
{
    int x = 10;
    int &ref = x;

    std::cout << "X=" << x << "ref=" << ref << std::endl;

    ref = 20;
    std::cout << "X=" << x << "ref=" << ref << std::endl;

    x = 30;
    std::cout << "X=" << x << "ref=" << ref << std::endl;

    std::cout << "Address of X=" << &x << "Address of ref=" << &ref << std::endl;

    std::vector<int> vect{10,20,30,40};

    for(auto &x:vect){
        x=x+5;
        std::cout<<x<<" "<<std::endl;
    }
    int y;
    for(auto y:vect){
        y=y+5;
        std::cout<<y<<" "<<std::endl;
    }
    std::cout<<"Address of vect"<<&vect[3]<<"address of x"<<&x<<"address of y"<<&y<<std::endl;


}