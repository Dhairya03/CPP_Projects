#include <iostream>

template <typename T>
void print(T value)
{
    // std::cout<<T<<std::endl;
    std::cout << value << std::endl;
}

template<typename T>
void count(T value){
    std::cout<<value<<std::endl;
}

int main()
{
    double val;
    std::cin>>val;
    print(5);
    print(val);
    // print("hello");
    // print(5);
    count(3.2);
    return 0;
}
