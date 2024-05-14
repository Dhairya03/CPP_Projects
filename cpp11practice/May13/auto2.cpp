#include <iostream>

auto fun(int a, int b)->decltype(a+b) { //mandatory to use trailing return type  in cpp11
    return a+b;
}


auto fun2()->int{
    int a=5;
    int&c=a;
    return c;
}
int main()
{
    auto a = 'a';//type of a is deduced as char at the time of declaration
    a = 56;
    std::cout << a << std::endl;
    
    a=fun(20,14); //whateever funtion returns will be converted into char only
    std::cout<<a<<std::endl;
    
    int b=5;
    int &c=b;
    auto z=&c;
    std::cout<<&b<<&c<<z<<std::endl;
    
    auto y=fun2();
    std::cout<<y<<std::endl;
}