#include<iostream>

class Base {
    int private_a,private_b;
    protected:
    int pro_a,pro_b;
    // void printMember(){
    //     std::cout<<private_a<<" "<<pro_a<<" "<<pub_a<<std::endl;
    // }
    public:
    int pub_a,pub_b;
     void printMember(){
        std::cout<<private_a<<" "<<pro_a<<" "<<pub_a<<std::endl;
    }

};

int main(){

    Base b;
    b.printMember();
    return 0;
}