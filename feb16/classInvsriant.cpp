#include<iostream>
#include <cassert>

struct Fraction
{
    int numerator{};
    int denominator{1};
};
void printFraction(Fraction &f){
    assert(f.denominator != 0);
    std::cout<<f.numerator/f.denominator<<std::endl;
}

int main(){
    Fraction f1{5,0};
    printFraction(f1);
}