#include <iostream>
    static int b=10;

int& GetValue()//if return typw is int it gives error
{
    return b;
}

int main()
{    std::cout << b;

    int a = GetValue();
    GetValue() = 5; //here GetValue becomes lvalue refrence after we change datatype to int& 
    
    std::cout << b;
}