#include<iostream>

int main(){
  // double input;
    try{
        std::cout<<"Enter something"<<std::endl;
        // std::cin>>input;
        // std::cout<<input;
        //throw 1;
        //throw 1.1;
        throw 'a';
        std::cout<<"After throw"<<std::endl;
    // }catch(int ch){
    //     std::cout<<"int Input is"<<ch<<std::endl;
    // }catch(double ch){
    //     std::cout<<"double Input is"<<ch<<std::endl;
    }catch(char ch){
        std::cout<<"char Input is"<<ch<<std::endl;
    }
}