#include <iostream>
#include "header.h"
#include "Common.h"

int main()
{
    int side;
    print("Enter side of square");
    std::cin >> side;
    int p=perimeter(side);
    std::cout<<p<<std::endl;
    int a=area(side);
    std::cout<<a<<std::endl;
}