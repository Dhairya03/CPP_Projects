#include <iostream>

template<typename T,int N>
class Array{
    private:
    T array[N];
    public:
    int getSize(){
        return N;
    }
};

int main(){
    Array<char,5> array;
    
    std::cout<<array.getSize();
    return 0;
}