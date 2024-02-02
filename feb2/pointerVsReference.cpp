#include<iostream>

int main(){
    int i=10;
    int * ptr=&i;
    int **ptr2=&ptr;
    int ***ptr3=&ptr2;

    int &ref=i;
    int &ref2=ref;
    int &ref3=ref2;

    std::cout<<i<<" "<<ptr<<" "<<ptr2<<" "<<ptr3<<" "<<ref<<" "<<ref2<<" "<<ref3<<std::endl;

    std::cout<<sizeof(ptr);
}