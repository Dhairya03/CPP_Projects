#include<iostream>

int main(){
    //stack allocation
    int value=5;
    int array[5];
    array[0]=1;
    array[1]=2;
    array[2]=3;
    array[3]=4;
    array[4]=5;

    std::cout<<&value<<" "<<array<<std::endl;

//heap allocation
    int*hvalue=new int;
    *hvalue=10;

    int *harray=new int[5];
    harray[0]=1;
    harray[1]=2;
    harray[2]=3;
    harray[3]=4;
    harray[4]=5;

        
    std::cout<<hvalue<<" "<<harray<<std::endl;
}