#include "iostream"
#include "header_file.h"
#define UPPER 25
int main(){
    int i;
    for(i=0;i<UPPER;i++){
        std::cout<<i<<std::endl;
    }
    add(1,2);
    multiply(2,4);
    
    return 0;
}